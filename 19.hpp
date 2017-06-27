// https://leetcode.com/problems/find-largest-value-in-each-tree-row/#/description
// 515. Find Largest Value in Each Tree Row
/*
You need to find the largest value in each row of a binary tree.

Example:
Input:

          1
         / \
        3   2
       / \   \
      5   3   9

Output: [1, 3, 9]
 */
#import <iostream>
#import <vector>
#import <stack>
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
class Solution19 {
public:
    vector<int> largestValues(TreeNode *root) {
        auto result = vector<int>();

        auto layer = stack<TreeNode *>();
        if (root) {
            layer.push(root);
        }
        int layerMax = INT32_MAX;
        auto nextLayer = stack<TreeNode *>();
        while (!layer.empty()) {
            TreeNode *curNode = layer.top();
            layer.pop();
            int curNum = curNode->val;
            if (curNum > layerMax) {
                layerMax = curNum;
            }

            if (curNode->left) {
                nextLayer.push(curNode->left);
            }
            if (curNode->right) {
                nextLayer.push(curNode->right);
            }

            if (layer.empty()) {
                result.push_back(layerMax);
                layerMax = INT32_MIN;

                if (!nextLayer.empty()) {
                    layer = nextLayer;
                    nextLayer = stack<TreeNode *>();
                }
            }
        }

        return result;
    }

    void test() {

    }
};
