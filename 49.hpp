// https://leetcode.com/problems/sum-of-left-leaves/#/description
// 404. Sum of Left Leaves
/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 */
#import <iostream>
#import "10.hpp"
#import <queue>

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
class Solution49 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }

        int result = this->visitNode(root, false);

        return result;
    }

    int visitNode(TreeNode *node, bool isLeft) {
        int result = 0;
        bool isLeaves = true;
        if (node->left) {
            result += this->visitNode(node->left, true);
            isLeaves = false;
        }
        if (node->right) {
            result += this->visitNode(node->right, false);
            isLeaves = false;
        }
        if (isLeft && isLeaves) {
            result += node->val;
        }

        return result;
    }

    void test() {

    }
};
