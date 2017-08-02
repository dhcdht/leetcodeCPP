// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
// 637. Average of Levels in Binary Tree
/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
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
class Solution94 {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        auto result = vector<double>();
        if (nullptr == root) {
            return result;
        }

        auto levelQueue = queue<TreeNode *>();
        levelQueue.push(root);
        levelQueue.push(nullptr);

        auto sum = 0.0;
        auto count = 0;
        while (!levelQueue.empty()) {
            auto front = levelQueue.front();
            levelQueue.pop();
            if (front == nullptr) {
                result.push_back(sum / count);
                sum = 0.0;
                count = 0;

                if (levelQueue.size() > 0) {
                    levelQueue.push(nullptr);
                }
            } else {
                sum += front->val;
                count += 1;

                if (front->left) {
                    levelQueue.push(front->left);
                }
                if (front->right) {
                    levelQueue.push(front->right);
                }
            }
        }

        return result;
    }

    void test() {
        auto root = new TreeNode(1);
        auto right = new TreeNode(1);
        root->right = right;

        auto result = this->averageOfLevels(root);
    }
};
