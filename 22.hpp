// https://leetcode.com/problems/most-frequent-subtree-sum/#/description
// 508. Most Frequent Subtree Sum
/*
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
 */
#import <iostream>
#import "10.hpp"
#import <unordered_map>
#import <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution22 {
private:
    unordered_map<int, int> m_valueCountMap;
    int m_currentMaxCount;

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        auto result = vector<int>();
        if (root == NULL) {
            return result;
        }

        this->traversalNode(root);

        for_each(m_valueCountMap.begin(), m_valueCountMap.end(), [&](unordered_map<int, int>::value_type value) {
            if (value.second == m_currentMaxCount) {
                result.push_back(value.first);
            }
        });

        return result;
    }

    int traversalNode(TreeNode *node) {
        int sum = 0;
        if (node->left) {
            sum += this->traversalNode(node->left);
        }
        if (node->right) {
            sum += this->traversalNode(node->right);
        }
        sum += node->val;

        int count = m_valueCountMap[sum];
        count += 1;
        m_valueCountMap[sum] = count;
        if (count > m_currentMaxCount) {
            m_currentMaxCount = m_valueCountMap[sum];
        }

        return sum;
    }

    void test() {

    }
};
