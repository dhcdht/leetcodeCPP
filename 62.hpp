// https://leetcode.com/problems/reorder-list/#/description
// 143. Reorder List
/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
// beats 72.56%
class Solution62 {
private:
    class TwoWayNode {
    public:
        ListNode *val;
        TwoWayNode *next;
        TwoWayNode *prev;

    public:
        TwoWayNode(ListNode *val) : val(val), next(NULL), prev(NULL) {}
    };

public:
    void reorderList(ListNode* head) {
        // 保证至少有两个节点，不然后边的步骤没有意义
        if (NULL == head
            || head->next == NULL) {
            return;
        }

        // 构建双向链表
        auto tHead = new TwoWayNode(head);
        auto curTNode = tHead;
        auto curNode = head->next;
        while (curNode != NULL) {
            auto tNode = new TwoWayNode(curNode);
            curTNode->next = tNode;
            tNode->prev = curTNode;

            curNode = curNode->next;
            curTNode = tNode;
        }
        auto tTail = curTNode;

        // 从头和尾一起遍历，将单链表的尾部插入到前边
        // 两个判断条件分别是单数和双数节点的情况
        while (tHead != tTail && tHead->next != tTail) {
            auto originNext = tHead->val->next;
            tHead->val->next = tTail->val;
            tTail->val->next = originNext;

            tHead = tHead->next;
            tTail = tTail->prev;
        }
        // 位置都放好后，最后一个节点的 next 还在指向原来的 next，我们给他改为 NULL
        tTail->val->next = NULL;
    }

    void test() {
        auto n1 = new ListNode(1);
        auto n2 = new ListNode(2);
        auto n3 = new ListNode(3);
        n1->next = n2;
        n2->next = n3;
        this->reorderList(n1);
    }
};
