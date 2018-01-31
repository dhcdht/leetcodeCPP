// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// 105. Construct Binary Tree from Preorder and Inorder Traversal
/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
class Solution99 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *ret = this->buildTree(preorder, inorder, 0, inorder.size() - 1);

        return ret;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int inorderLeft, int inorderRight) {
        if (inorderLeft > inorderRight) {
            return nullptr;
        }

        int inNodeNumber = preorder.front();
        preorder.erase(preorder.begin());

        TreeNode *inNode = new TreeNode(inNodeNumber);
        int inorderMiddle = inorderLeft;
        while (inorderMiddle < inorderRight) {
            if (inorder[inorderMiddle] == inNodeNumber) {
                break;
            }

            inorderMiddle += 1;
        }

        TreeNode *leftNode = buildTree(preorder, inorder, inorderLeft, inorderMiddle - 1);
        TreeNode *rightNode = buildTree(preorder, inorder, inorderMiddle + 1, inorderRight);
        inNode->left = leftNode;
        inNode->right = rightNode;

        return inNode;
    }

    void test() {
        vector<int> preorder = {3, 9, 20, 15, 7};
        vector<int> inorder = {9, 3, 15, 20, 7};
//        vector<int> preorder = {1, 2};
//        vector<int> inorder = {2, 1};
        TreeNode *result = this->buildTree(preorder, inorder);
    }
};
