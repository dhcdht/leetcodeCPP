// https://leetcode.com/problems/linked-list-random-node/#/description
// 382. Linked List Random Node
/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
 */
#import <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 查到的资料
// https://en.wikipedia.org/wiki/Reservoir_sampling
// http://blog.csdn.net/clearriver/article/details/4846354
class Solution48 {
private:
    ListNode *m_head;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution48(ListNode* head) {
        m_head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        auto k = 1;
        auto i = k + 1;
        // 因为 k = 1，所以 k+1 直接可以 next 取到
        auto node = m_head->next;
        int result = m_head->val;

        while (node) {
            int randomNum = random() % i;
            // 它要和第 0 个交换的话，那么它被随机到了
            if (randomNum == 0) {
                result = node->val;
            }

            i += 1;
            node = node->next;
        }

        return result;
    }

    void test() {

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
