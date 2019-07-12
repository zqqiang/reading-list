/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (53.71%)
 * Total Accepted:    235.9K
 * Total Submissions: 435K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int begin = 1, end = 1, n = nums.size();
        vector<int> ans(nums.size(), 1);
        for(int i = 0; i < n; i++) {
            ans[i] *= begin;
            begin *= nums[i];
            ans[n - i -1] *= end;
            end *= nums[n - i - 1];
        }
        return ans;
    }
};

