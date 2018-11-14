package leetcode

import (
	"bytes"
	"math"
)

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

/*
4. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	return float64(0.0)
}

/*
5. Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/
func isPalindromic(s string, start int, end int) bool {
	if end-start > 0 {
		for i, j := start, end; i < j; {
			if s[i] == s[j] {
				if i+1 == j {
					return true
				}
				i++
				j--
			} else {
				return false
			}
		}
		return true
	}
	return false
}

func longestPalindrome(s string) string {
	maxStart := 0
	maxEnd := 0
	if len(s) == 0 {
		return s
	}
	for i := 0; i < len(s); i++ {
		for j := i + 1; j < len(s); j++ {
			if isPalindromic(s, i, j) {
				if (maxEnd - maxStart) < j-i+1 {
					maxEnd = j
					maxStart = i
				}
			}
		}
	}
	return s[maxStart : maxEnd+1]
}

/*
6. ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	numCols := 0
	if len(s) < (2*numRows - 2) {
		numCols = len(s)%numRows + 1
	} else {
		m := len(s) / (2*numRows - 2)
		n := len(s) % (2*numRows - 2)
		numCols = m*(numRows-1) + (n / numRows) + (n % numRows)
	}

	target := make([]byte, numRows*numCols)
	row := 0
	col := 0
	for i := 0; i < len(s); i++ {
		target[numCols*row+col] = s[i]
		if (row == (numRows - 1)) || 0 != (col%(numRows-1)) {
			row--
			col++
		} else {
			row++
		}
	}
	var buffer bytes.Buffer
	for i := 0; i < numCols*numRows; i++ {
		if target[i] != 0 {
			buffer.WriteByte(target[i])
		}
	}
	return buffer.String()
}

/*
7. Reverse Integer
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

func reverse(x int) int {
	var result int
	var step uint
	for ; x != 0; step += 4 {
		m := (x % 10)
		x = x / 10
		result = (result*10 + m)
	}
	if result > (int(math.Pow(2, 31))-1) || result < -int(math.Pow(2, 31)) {
		return 0
	}
	return result
}

/*
8. String to Integer (atoi)
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/
func myAtoi(str string) int {
	// todo: not working
	var sign byte
	var result int
	var step int

	const (
		MaxInt32 = 1<<31 - 1
		MinInt32 = -1 << 31
	)

	for i := 0; i < len(str); i++ {
		if str[i] == '+' || str[i] == '-' {
			sign = str[i]
		} else if str[i] >= 0 && str[i] <= 9 {
			if step == 0 {
				result += (int(str[i]) - '0')
			} else {
				result += (int(str[i]) - '0') * step * 10
			}
			step++
		} else if str[i] == ' ' {

		} else if step == 0 {
			return 0
		} else if step != 0 {
			break
		}
	}

	if sign == '-' {
		result *= -1
	}

	if result > MaxInt32 {
		return MaxInt32
	} else if result < MinInt32 {
		return MinInt32
	} else {
		return result
	}
}
