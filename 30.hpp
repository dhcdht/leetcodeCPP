// https://leetcode.com/problems/invert-binary-tree/#/description
// 226. Invert Binary Tree
/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
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
class Solution30 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (NULL == root) {
            return NULL;
        }

        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        if (root->left) {
            this->invertTree(root->left);
        }
        if (root->right) {
            this->invertTree(root->right);
        }

        return root;
    }

    void test() {

    }
};
