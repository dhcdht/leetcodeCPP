// https://leetcode.com/problems/intersection-of-two-linked-lists/#/description
// 160. Intersection of Two Linked Lists
/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
class Solution72 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto node1 = headA;
        auto node2 = headB;
        while (node1 != node2) {
            if (node1 == nullptr) {
                node1 = headA;
            } else {
                node1 = node1->next;
            }

            if (node2 == nullptr) {
                node2 = headB;
            } else {
                node2 = node2->next;
            }
        }

        return node1;
    }

    void test() {

    }
};
