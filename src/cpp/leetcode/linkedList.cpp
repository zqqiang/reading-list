/*
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
/*
LintCode
767. Reverse Array

Inplace means you can't use extra space.

Have you met this question in a real interview?  
Example
Given nums = [1,2,5]
return [5,2,1]
*/
class Solution {
public:
    /**
     * @param nums: a integer array
     * @return: nothing
     */
    void reverseArray(vector<int> &nums) {
        // write your code here
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
    }
};
/*
344. Reverse String (todo)
Write a function that reverses a string. 
The input string is given as an array of characters char[].

Do not allocate extra space for another array, 
you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            int tmp = s[j];
            s[j] = s[i];
            s[i] = tmp;
            i++;j--;
        }
    }
};
/*
445. Add Two Numbers II
You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? 
In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> left;
        vector<int> right;
        while(l1) {
            left.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            right.push_back(l2->val);
            l2 = l2->next;
        }
        int left_size = left.size();
        int right_size = right.size();
        int longer = max(left_size, right_size);
        int sum = 0, carry = 0;
        ListNode* prev = NULL;
        for(int i = 0; i < longer; i++) {
            if(i < left_size && i < right_size) {
                sum = left.back() + right.back();
                left.pop_back();
                right.pop_back();
            } else if(i < left_size && i >= right_size) {
                sum = left.back();
                left.pop_back();
            } else if(i < right_size && i >= left_size) {
                sum = right.back();
                right.pop_back();
            }
            ListNode* curr = new ListNode((sum + carry) % 10);
            curr->next = prev;
            prev = curr;
            carry = (sum + carry)/10;
        }
        if(carry) {
            ListNode* curr = new ListNode(carry);
            curr->next = prev;
            prev = curr;
        }
        return prev;
    }
};
/*
LintCode
649. Binary Tree Upside Down
Description
Given a binary tree where all the right nodes are either leaf nodes with a sibling 
(a left node that shares the same parent node) or empty, 
flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. 
Return the new root.

Have you met this question in a real interview?  
Example
Given a binary tree {1,2,3,4,5}

    1
   / \
  2   3
 / \
4   5
return the root of the binary tree {4,5,2,#,#,3,1}.

   4
  / \
 5   2
    / \
   3   1  
*/
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
private:
    TreeNode* helper(TreeNode* node) {
        if(NULL == node->left) {
            return node;
        }
        TreeNode* newNode = helper(node->left);
        node->left->right = node;
        node->left->left = node->right;
        node->left = NULL;
        node->right = NULL;
        return newNode;
    }

public:
    /**
     * @param root: the root of binary tree
     * @return: new root
     */
    TreeNode * upsideDownBinaryTree(TreeNode * root) {
        // write your code here
        if (NULL == root) {
            return NULL;
        }
        return helper(root);
    }
};
/*
234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
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
    ListNode* header;
    bool helper (ListNode* curr) {
        if (NULL == curr) {
            return true;
        }
        bool ans = helper(curr->next) && (header->val == curr->val);
        header = header->next;
        return ans;
    }
public:
    bool isPalindrome(ListNode* head) {
        header = head;
        return helper(head);
    }
};