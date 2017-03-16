// https://leetcode.com/problems/queue-reconstruction-by-height/#/description
// 406. Queue Reconstruction by Height
/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */
#import <iostream>
#import <algorithm>
#import <map>

using namespace std;

class Solution13 {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto result = vector<pair<int, int>>();

        auto indexMap = map<int, map<int, pair<int, int>>>();
        for_each(people.begin(), people.end(), [&](pair<int, int> p) {
            auto index = -p.first;
            auto map = indexMap[index];
            map[p.second] = p;
            indexMap[index] = map;
        });

        for (auto map : indexMap) {
            for (auto val : map.second) {
                result.insert(result.begin()+val.first, val.second);
            }
        }

        return result;
    }

    void test() {
        auto input = vector<pair<int, int>>(
                {
                        {7, 0},
                        {4, 4},
                        {7, 1},
                        {5, 0},
                        {6, 1},
                        {5, 2},
                }
        );
        auto result = this->reconstructQueue(input);
        cout << "406. Queue Reconstruction by Height : ";
        cout << "[";
        for_each(result.begin(), result.end(), [&](pair<int, int> val) {
            cout << "[" << val.first << "," << val.second << "]";
        });
        cout << "]" << endl;
    }
};
