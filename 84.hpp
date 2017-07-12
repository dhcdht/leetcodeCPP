// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/#/description
// 109. Convert Sorted List to Binary Search Tree
/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */
#import <iostream>
#import "48.hpp"
#import "10.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution84 {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        auto listArray = vector<ListNode *>();
        auto node = head;
        while (node != NULL) {
            listArray.push_back(node);
            node = node->next;
        }

        auto result = this->listNodeArraytoBST(listArray, 0, listArray.size() - 1);

        return result;
    }

    TreeNode *listNodeArraytoBST(vector<ListNode *> &listArray, int left, int right) {
        if (left > right) {
            return NULL;
        }

        auto mid = (left + right) / 2;
        auto treeNode = new TreeNode(listArray[mid]->val);

        treeNode->left = this->listNodeArraytoBST(listArray, left, mid - 1);
        treeNode->right = this->listNodeArraytoBST(listArray, mid + 1, right);

        return treeNode;
    }

    void test() {

    }
};
