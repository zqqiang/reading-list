/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* after = head;
        int steps = n + 1;
        ListNode* before = head;
        while(after && steps) {
            after = after->next;
            steps--;
        }
        while(before && after) {
            before = before->next;
            after = after->next;
        }
        if(before->next && !steps) {
            before->next = before->next->next;
            return head;
        }
        if(head == before && 1 == steps) {
            return head->next;
        }

        return NULL;
    }
};

