// https://leetcode.com/problems/binary-tree-level-order-traversal/#/description
// 102. Binary Tree Level Order Traversal
/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

 */
#import <iostream>
#import "10.hpp"
#import <queue>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution87 {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        auto result = vector<vector<int>>();
        if (root == nullptr) {
            return result;
        }
        auto queue = std::queue<TreeNode *>();
        // 作为第一行的开始标志
        queue.push(nullptr);
        queue.push(root);

        while (queue.size() > 0) {
            auto front = queue.front();
            if (front == nullptr) {
                if (queue.size() != 1) {
                    auto row = vector<int>();
                    result.push_back(row);
                    queue.push(nullptr);
                }
            } else {
                result.back().push_back(front->val);
                if (front->left) {
                    queue.push(front->left);
                }
                if (front->right) {
                    queue.push(front->right);
                }
            }
            queue.pop();
        }

        return result;
    }

    void test() {

    }
};
