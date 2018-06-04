// https://leetcode.com/problems/trim-a-binary-search-tree/description/
// 669. Trim a Binary Search Tree
/*
Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

Example 1:
Input:
    1
   / \
  0   2

  L = 1
  R = 2

Output:
    1
      \
       2
Example 2:
Input:
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

Output:
      3
     /
   2
  /
 1
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
class Solution124 {
public:
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        if (nullptr == root) {
            return nullptr;
        }

        if (root->left) {
            TreeNode *leftNode = this->trimBST(root->left, L, R);
            root->left = leftNode;
        }

        TreeNode *midNode = root;
        if (root->val < L) {
            midNode = this->replaceBST(root, L, R);
        } else if (R < root->val) {
            midNode = this->replaceBST(root, L, R);
        }

        if (root->right) {
            TreeNode *rightNode = this->trimBST(root->right, L, R);
            root->right = rightNode;
        }

        return midNode;
    }

    TreeNode *replaceBST(TreeNode *root, int L, int R) {
        if (nullptr == root) {
            return nullptr;
        }

        if (R < root->val) {
            return this->replaceBST(root->left, L, R);
        } else if (L <= root->val) {
            return root;
        } else {
            return this->replaceBST(root->right, L, R);
        }
    }

    void test() {

    }
};