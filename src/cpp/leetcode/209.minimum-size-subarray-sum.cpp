/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (34.57%)
 * Total Accepted:    171.2K
 * Total Submissions: 494.9K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int l = 0, r = 0, sums = 0, n = nums.size(), len = INT_MAX;
        while (r < n)
        {
            sums += nums[r++];
            while (sums >= s)
            {
                len = min(len, r - l);
                sums -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};
