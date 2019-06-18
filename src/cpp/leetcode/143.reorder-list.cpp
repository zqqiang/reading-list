/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reorderList(ListNode *head, int len)
    {
        if (len == 0)
            return NULL;
        if (len == 1)
            return head;
        if (len == 2)
            return head->next;
        ListNode *tail = reorderList(head->next, len - 2);
        ListNode *tmp = tail->next;
        tail->next = tail->next->next;
        tmp->next = head->next;
        head->next = tmp;
        return tail;
    }

    int getLength(ListNode *head)
    {
        int len = 0;
        while (head != NULL)
        {
            ++len;
            head = head->next;
        }
        return len;
    }

    void reorderList(ListNode *head)
    {
        ListNode *tail = NULL;
        tail = reorderList(head, getLength(head));
    }
};
