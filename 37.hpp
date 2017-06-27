// https://leetcode.com/problems/minimum-absolute-difference-in-bst/#/description
// 530. Minimum Absolute Difference in BST
/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.
 */
#import <iostream>
#import "10.hpp"

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
class Solution37 {
private:
    bool m_isFirst = true;
    int m_lastVal = 0;
    int m_currentMinimum = INT32_MAX;

public:
    int getMinimumDifference(TreeNode *root) {
        if (root->left) {
            this->getMinimumDifference(root->left);
        }

        if (!m_isFirst) {
            int difference = abs(m_lastVal - root->val);
            if (difference < m_currentMinimum) {
                m_currentMinimum = difference;
            }

            m_lastVal = root->val;
        } else {
            m_lastVal = root->val;
            m_isFirst = false;
        }

        if (root->right) {
            this->getMinimumDifference(root->right);
        }

        return m_currentMinimum;
    }

    void test() {

    }
};
