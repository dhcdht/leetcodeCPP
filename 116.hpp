// https://leetcode.com/problems/lfu-cache/description/
// 460. LFU Cache
/*
Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LFUCache cache = new LFUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
 */
#import <iostream>
#import <unordered_map>
#import <map>
#import <list>

class Solution116 {
private:
    int m_capacity;
    unordered_map<int, int> m_mapValue;
    int m_minFrequency;
    unordered_map<int, int> m_mapFrequency;
    map<int, list < int>> m_mapRecently;
    unordered_map<int, list<int>::iterator> m_mapIT;

public:
    void LFUCache(int capacity) {
        m_capacity = capacity;
        m_minFrequency = 1;
    }

    int get(int key) {
        auto it = m_mapValue.find(key);
        if (it == m_mapValue.end()) {
            return -1;
        }
        int value = (*it).second;

        this->addFrequency(key);

        return value;
    }

    void put(int key, int value) {
        auto it = m_mapValue.find(key);
        if (it == m_mapValue.end()) {
            int frequency = 0;
            // add
            {
                m_mapValue[key] = value;
                frequency += 1;
                m_mapFrequency[key] = frequency;
                auto listIT = m_mapRecently.find(frequency);
                if (listIT == m_mapRecently.end()) {
                    m_mapRecently[frequency] = list<int>();
                }
                m_mapRecently[frequency].push_back(key);
                auto endIT = m_mapRecently[frequency].end();
                endIT--;
                m_mapIT[key] = endIT;
            }

            if (m_mapValue.size() > m_capacity) {
                int minKey = m_mapRecently[m_minFrequency].front();
                auto minIT = m_mapIT[minKey];
                // remove
                {
                    m_mapValue.erase(minKey);
                    m_mapFrequency.erase(minKey);
                    m_mapRecently[m_minFrequency].erase(minIT);
                    if (m_mapRecently[m_minFrequency].empty()) {
                        m_mapRecently.erase(m_minFrequency);
                    }
                    m_mapIT.erase(minKey);
                };
            }
            // refresh m_minFrequency
            m_minFrequency = 1;
        } else {
            m_mapValue[key] = value;

            this->addFrequency(key);
        }
    }

    void addFrequency(int key) {
        int frequency = m_mapFrequency[key];
        auto it = m_mapIT[key];
        // remove
        {
            m_mapRecently[frequency].erase(it);
            if (m_mapRecently[frequency].empty()) {
                m_mapRecently.erase(frequency);
            }
            m_mapIT.erase(key);
        }
        // add
        {
            if (m_minFrequency == frequency && m_mapRecently.find(frequency) == m_mapRecently.end()) {
                m_minFrequency = frequency + 1;
            }
            frequency += 1;
            m_mapFrequency[key] = frequency;
            auto listIT = m_mapRecently.find(frequency);
            if (listIT == m_mapRecently.end()) {
                m_mapRecently[frequency] = list<int>();
            }
            m_mapRecently[frequency].push_back(key);
            auto endIT = m_mapRecently[frequency].end();
            endIT--;
            m_mapIT[key] = endIT;
        }
    }

    void test() {
//        /*
//         * ["LFUCache", "put",  "put",  "get",  "put",  "get",  "get",  "put",  "get",  "get",  "get"]
//         * [[2],        [1,1],  [2,2],  [1],    [3,3],  [2],    [3],    [4,4],  [1],    [3],    [4]]
//         */
//        LFUCache(2);
//        this->put(1, 1);
//        this->put(2, 2);
//        int result = this->get(1);
//        this->put(3, 3);
//        result = this->get(2);
//        result = this->get(3);
//        this->put(4, 4);
//        result = this->get(1);
//        result = this->get(3);
//        result = this->get(4);
        /*
         * ["LFUCache", "put",  "put",  "get",  "get",  "get",  "put",  "put",  "get",  "get",  "get",  "get"]
         * [[3],        [2,2],  [1,1],  [2],    [1],    [2],    [3,3],  [4,4],  [3],    [2],    [1],    [4]]
         */
        LFUCache(3);
        this->put(2, 2);
        this->put(1, 1);
        int result = this->get(2);
        result = this->get(1);
        result = this->get(2);
        this->put(3, 3);
        this->put(4, 4);
        result = this->get(3);
        result = this->get(2);
        result = this->get(1);
        result = this->get(4);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
