/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (42.74%)
 * Total Accepted:    274.2K
 * Total Submissions: 641K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }
        int l = 0;
        int r = nums.size() - 1;
        
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] >= nums[l] && nums[mid] > nums[r]) {
                l = mid  + 1;
            } else {
                r = mid;
            }
        }
        
        return nums[l];
    }
};

