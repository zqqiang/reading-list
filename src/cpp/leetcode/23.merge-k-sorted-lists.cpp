/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (32.73%)
 * Total Accepted:    335.6K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(0 == lists.size()) return NULL;
        if(1 == lists.size()) return lists[0];
        ListNode* ans = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            ListNode* curr = lists[i];
            ListNode* sorted = ans;
            while(sorted && curr) {
                if(sorted->val <= curr->val) {
                    ListNode* next = sorted->next;
                    sorted->next = curr;
                    sorted = next;
                    curr = curr->next;
                } else {
                    ListNode* next = curr->next;
                    curr->next = sorted;
                    curr = next;
                    sorted = sorted->next;
                }
            }
        }
        return ans;
    }
};
