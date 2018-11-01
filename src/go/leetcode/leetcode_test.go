package leetcode

/*
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var sum int
	var incr int
	var last *ListNode
	var head *ListNode
	var cur *ListNode

	if l1 != nil && l2 != nil {
		sum = l1.Val + l2.Val
		incr = sum / 10

		cur = &ListNode{sum % 10, nil}
		head = cur
		last = cur

		l1 = l1.Next
		l2 = l2.Next
		for l1 != nil || l2 != nil || incr != 0 {
			if l1 != nil && l2 != nil {
				sum = l1.Val + l2.Val + incr
				cur = &ListNode{sum % 10, nil}
				incr = sum / 10
				l1 = l1.Next
				l2 = l2.Next
			} else if l1 != nil && l2 == nil {
				sum = l1.Val + incr
				cur = &ListNode{sum % 10, nil}
				incr = sum / 10
				l1 = l1.Next
			} else if l1 == nil && l2 != nil {
				sum = l2.Val + incr
				cur = &ListNode{sum % 10, nil}
				incr = sum / 10
				l2 = l2.Next
			} else if incr != 0 {
				cur = &ListNode{incr % 10, nil}
				incr = 0
			}
			last.Next = cur
			last = cur
		}
		return head
	}

	return nil
}

/*
3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

func lengthOfLongestSubstring(s string) int {
    return 0
}