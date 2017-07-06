// https://leetcode.com/problems/recover-binary-search-tree/#/description
// 99. Recover Binary Search Tree
/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

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
class Solution79 {
    TreeNode *nodeBigger;
    TreeNode *nodeSmaller;
    TreeNode *prevNode;

public:
    void recoverTree(TreeNode *root) {
        traversalNode(root);

        int tmp = nodeBigger->val;
        nodeBigger->val = nodeSmaller->val;
        nodeSmaller->val = tmp;
    }

    void traversalNode(TreeNode *node) {
        if (NULL == node) {
            return;
        }

        traversalNode(node->left);

        if (nodeBigger == NULL && prevNode != NULL && node && prevNode->val > node->val) {
            nodeBigger = prevNode;
        }
        if (nodeBigger != NULL && prevNode->val > node->val) {
            nodeSmaller = node;
        }
        prevNode = node;

        traversalNode(node->right);
    }

    void test() {

    }
};
