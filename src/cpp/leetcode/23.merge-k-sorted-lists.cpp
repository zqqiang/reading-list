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
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode res(0);
        ListNode* temp = &res;
        while(l1 && l2) {
            if(l1->val > l2->val) {
                temp->next = l2;
                l2 = l2->next;
            } else {
                temp->next = l1;
                l1 = l1->next;
            }
            temp = temp->next;
        }
        temp->next = (l1 ? l1 : l2);
        return res.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int step = 1;
        while(step < lists.size()) {
            for(int i = 0; i + step < lists.size(); i += (step*2)) {
                lists[i] = mergeTwoLists(lists[i], lists[i + step]);
            }
            step *= 2;
        }
        return lists.empty() ? NULL : lists[0];
    }
};
