// https://leetcode.com/problems/odd-even-linked-list/description/
// 328. Odd Even Linked List
/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
 */
#import <iostream>
#import "48.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution95 {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (nullptr == head) {
            return nullptr;
        }

        ListNode *oddListNode = head;
        ListNode *evenListNode = head->next;
        auto evenListHead = evenListNode;

        auto oddNode = evenListNode != nullptr ? evenListNode->next : nullptr;
        while (oddNode) {
            oddListNode->next = oddNode;
            oddListNode = oddNode;
            evenListNode->next = oddNode->next;
            evenListNode = oddNode->next;

            if (nullptr != evenListNode) {
                oddNode = evenListNode->next;
            } else {
                oddNode = nullptr;
            }
        }
        oddListNode->next = evenListHead;

        return head;
    }

    void test() {
        auto vals = vector<int>({1, 2, 3});
        ListNode *head = nullptr;
        ListNode *node = nullptr;
        for (auto v : vals) {
            auto n = new ListNode(v);
            if (nullptr == head) {
                head = n;
                node = n;
            } else {
                node->next = n;
                node = n;
            }
        }

        auto result = this->oddEvenList(head);
    }
};
