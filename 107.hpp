// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
// 107. Binary Tree Level Order Traversal II
/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
 */
#import <iostream>
#import "10.hpp"
#import <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution107 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> results;
        if (nullptr == root) {
            return results;
        }

        vector<vector<TreeNode *>> levels;
        vector<TreeNode *> levelNodes;
        levelNodes.push_back(root);
        levels.push_back(levelNodes);
        bool hasLeafNode = false;
        do {
            vector<TreeNode *> nextLevelNodes;
            auto curLevelNodes = levels.back();
            for (auto node : curLevelNodes) {
                if (node->left != nullptr) {
                    nextLevelNodes.push_back(node->left);
                }
                if (node->right != nullptr) {
                    nextLevelNodes.push_back(node->right);
                }
            }
            if (!nextLevelNodes.empty()) {
                hasLeafNode = true;
                levels.push_back(nextLevelNodes);
            } else {
                hasLeafNode = false;
            }
        } while (hasLeafNode);

        for (int i = 0; i < levels.size(); ++i) {
            auto levelNodes = levels[levels.size() - 1 - i];
            vector<int> nodes;
            for (int j = 0; j < levelNodes.size(); ++j) {
                auto node = levelNodes[j];
                nodes.push_back(node->val);
            }
            results.push_back(nodes);
        }

        return results;
    }

    void test() {

    }
};
