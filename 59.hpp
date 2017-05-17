// https://leetcode.com/problems/implement-trie-prefix-tree/#/description
// 208. Implement Trie (Prefix Tree)
/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
 */
#import <iostream>
#import <string>
#import <unordered_map>

class Trie {
private:
    class TrieNode {
    public:
        TrieNode() {
            m_isEndNode = false;
            m_nextNodes = new unordered_map<char, TrieNode *>();
        }

        ~TrieNode() {
            delete m_nextNodes;
        }

        bool m_isEndNode;
        unordered_map<char, TrieNode *> *m_nextNodes;
    };

    TrieNode *findEndNode(string word) {
        if (word.size() <= 0) {
            return NULL;
        }

        auto currentNode = m_head;
        for (char c : word) {
            auto next = (currentNode->m_nextNodes)->operator[](c);
            if (next != NULL) {
                currentNode = next;
            } else {
                return NULL;
            }
        }

        return currentNode;
    }

    TrieNode *m_head;

public:
    /** Initialize your data structure here. */
    Trie() {
        m_head = new TrieNode();
    }

    ~Trie() {
        delete m_head;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto currentNode = m_head;
        for (char c : word) {
            auto next = (currentNode->m_nextNodes)->operator[](c);
            if (next == NULL) {
                next = new TrieNode();
                currentNode->m_nextNodes->operator[](c) = next;
            }

            currentNode = next;
        }

        if (currentNode != m_head) {
            currentNode->m_isEndNode = true;
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto endNode = this->findEndNode(word);

        if (endNode != NULL && endNode->m_isEndNode) {
            return true;
        } else {
            return false;
        }
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto endNode = this->findEndNode(prefix);

        if (endNode != NULL) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
