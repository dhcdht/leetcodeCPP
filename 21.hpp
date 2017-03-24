// https://leetcode.com/problems/convert-bst-to-greater-tree/#/description
// 538. Convert BST to Greater Tree
/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
 */
#import <iostream>
#import "10.hpp"
#import <stack>

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
class Solution21 {
private:
    int m_currentSum = 0;

public:
    TreeNode* convertBST(TreeNode* root) {
        if (root) {
            this->LRDWalkNode(root);
        }

        return root;
    }

    void LRDWalkNode(TreeNode *node) {
        if (node->right) {
            this->LRDWalkNode(node->right);
        }

        int nodeValue = node->val;
        node->val += m_currentSum;
        m_currentSum += nodeValue;

        if (node->left) {
            this->LRDWalkNode(node->left);
        }
    }

    void test() {

    }
};
