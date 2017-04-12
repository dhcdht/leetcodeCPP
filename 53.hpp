// https://leetcode.com/problems/add-two-numbers-ii/#/description
// 445. Add Two Numbers II
/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
 */
#import <iostream>
#import "48.hpp"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution53 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int leftCount = 0;
        int rightCount = 0;
        ListNode *leftNode = l1;
        ListNode *rightNode = l2;
        while (leftNode || rightNode) {
            if (leftNode) {
                leftCount += 1;
                leftNode = leftNode->next;
            }
            if (rightNode) {
                rightCount += 1;
                rightNode = rightNode->next;
            }
        }

        ListNode *node = NULL;
        leftNode = l1;
        rightNode = l2;
        while (leftNode || rightNode) {
            if (leftCount > rightCount) {
                ListNode *next = new ListNode(leftNode->val);

                leftCount -= 1;
                leftNode = leftNode->next;

                next->next = node;
                node = next;
            } else if (rightCount > leftCount) {
                ListNode *next = new ListNode(rightNode->val);

                rightCount -= 1;
                rightNode = rightNode->next;

                next->next = node;
                node = next;
            } else {
                ListNode *next = new ListNode(0);
                next->val = leftNode->val + rightNode->val;

                leftCount -= 1;
                leftNode = leftNode->next;
                rightCount -= 1;
                rightNode = rightNode->next;

                next->next = node;
                node = next;
            }
        }

        ListNode *nextNode = node->next;
        node->next = NULL;
        int carry = 0;
        while (nextNode) {
            node->val += carry;
            carry = node->val / 10;
            node->val %= 10;

            ListNode *next = nextNode->next;
            nextNode->next = node;
            node = nextNode;
            nextNode = next;
        }
        node->val += carry;
        carry = node->val / 10;
        node->val %= 10;
        if (carry > 0) {
            ListNode *next = new ListNode(carry);
            next->next = node;
            node = next;
        }

        return node;
    }

    void test() {
        auto a = new ListNode(7);
        {
            auto last = a;
            for (auto num : {2, 4, 3}) {
                auto node = new ListNode(num);
                last->next = node;
                last = node;
            }
        }
        auto b = new ListNode(5);
        {
            auto last = b;
            for (auto num : {6, 4}) {
                auto node = new ListNode(num);
                last->next = node;
                last = node;
            }
        }
        this->addTwoNumbers(a, b);
    }
};
