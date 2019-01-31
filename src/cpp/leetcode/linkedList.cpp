/*
767. Reverse Array
221. Add Two Numbers II
649. Binary Tree Upside Down
223. Palindrome Linked List
450. Reverse Nodes in k-Group
53. Reverse Words in a String
*/
/*
92. Reverse Linked List II
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        int start = 1;
        int end = 0;
        while(curr && start != m) {
            prev = curr;
            curr = curr->next;
            start++;
        }
        ListNode* con = prev;
        ListNode* tail = curr;
        end = start;
        while(curr && end != n+1) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            end++;
        }
        if (con != NULL) {
            con->next = prev;
        } else {
            head = prev;
        }
        tail->next = curr;
        return head;
    }
};