// https://leetcode.com/problems/validate-binary-search-tree/
// 98. Validate Binary Search Tree
/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
 */
#import <iostream>
#import "10.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution91 {
private:
    bool m_valHasSet;
    int m_lastVal;
public:
    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        m_valHasSet = false;
        m_lastVal = INT32_MIN;

        return this->LMRValidBST(root);
    }

    bool LMRValidBST(TreeNode *node) {
        if (node->left) {
            if (!this->LMRValidBST(node->left)) {
                return false;
            }
        }

        if (m_valHasSet && node->val <= m_lastVal) {
            return false;
        }
        m_lastVal = node->val;
        m_valHasSet = true;

        if (node->right) {
            if (!this->LMRValidBST(node->right)) {
                return false;
            }
        }

        return true;
    }

    void test() {}
};
