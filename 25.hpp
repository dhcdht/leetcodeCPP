// https://leetcode.com/problems/maximum-depth-of-binary-tree/#/description
// 104. Maximum Depth of Binary Tree
/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
class Solution25 {
public:
    int maxDepth(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }

        int leftDepth = 0;
        if (root->left) {
            leftDepth = this->maxDepth(root->left);
        }

        int rightDepth = 0;
        if (root->right) {
            rightDepth = this->maxDepth(root->right);
        }

        if (leftDepth >= rightDepth) {
            return leftDepth + 1;
        } else {
            return rightDepth + 1;
        }
    }

    void teset() {

    }
};
