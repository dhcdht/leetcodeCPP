// https://leetcode.com/problems/find-bottom-left-tree-value/#/description
// 513. Find Bottom Left Tree Value
/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
 */
#import <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution10 {
public:
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode *> queue1 = queue<TreeNode*>();
        queue1.push(root);
        TreeNode *lastNode;
        while (!queue1.empty()) {
            lastNode = queue1.front();

            if (lastNode->right != nullptr) {
                queue1.push(lastNode->right);
            }
            if (lastNode->left != nullptr) {
                queue1.push(lastNode->left);
            }

            queue1.pop();
        }

        return lastNode->val;
    }

    void test() {

    }
};
