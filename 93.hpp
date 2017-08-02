// https://leetcode.com/problems/word-search-ii/description/
// 212. Word Search II
/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
 */
#import <iostream>

class Solution93 {
private:
    class CharNode {
    public:
        string word;
        vector<CharNode *> m_nexts;

    public:
        CharNode() : word(""), m_nexts(vector<CharNode *>(26, nullptr)) {
        }
    };

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        auto result = vector<string>();
        if (words.empty()) {
            return result;
        }

        auto wordCharVectorHead = this->buildWordCharVectors(words);

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                this->findContainWords(board, i, j, wordCharVectorHead, result);
            }
        }

        return result;
    }

    CharNode *buildWordCharVectors(vector<string> &words) {
        auto head = new CharNode();

        for (auto word : words) {
            auto curNode = head;
            for (auto c : word) {
                if (curNode->m_nexts[c - 'a'] == nullptr) {
                    auto charNode = new CharNode();
                    curNode->m_nexts[c - 'a'] = charNode;
                }

                curNode = curNode->m_nexts[c - 'a'];
            }
            curNode->word = word;
        }

        return head;
    }

    void findContainWords(vector<vector<char>> &board, int i, int j, CharNode *node, vector<string> &result) {
        auto c = board[i][j];
        if (c == '0') {
            return;
        }
        auto nNode = node->m_nexts[c - 'a'];

        if (nNode == nullptr) {
            return;
        } else if (!nNode->word.empty()) {
            result.push_back(nNode->word);
            nNode->word = "";
        }

        board[i][j] = '0';
        if (i + 1 < board.size()) {
            this->findContainWords(board, i + 1, j, nNode, result);
        }
        if (j + 1 < board[0].size()) {
            this->findContainWords(board, i, j + 1, nNode, result);
        }
        if (i > 0) {
            this->findContainWords(board, i - 1, j, nNode, result);
        }
        if (j > 0) {
            this->findContainWords(board, i, j - 1, nNode, result);
        }
        board[i][j] = c;
    }

    void test() {

    }
};

