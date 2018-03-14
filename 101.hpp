// https://leetcode.com/problems/linked-list-cycle/description/
// 141. Linked List Cycle
/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
class Solution101 {
public:
    bool hasCycle(ListNode *head) {
        if (nullptr == head) {
            return false;
        }

        ListNode *before = head;
        ListNode *after = head;
        do {
            after = after->next;
            if (nullptr == before->next || nullptr == before->next->next) {
                return false;
            }
            before = before->next->next;
        } while (before != after);

        return true;
    }

    void test() {

    }
};
