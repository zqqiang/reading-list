/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
class Solution {
private:
    int helper(vector<int>& nums, int begin, int end) {
        int prevOne = 0;
        int prevTwo = 0;
        for(int i = begin; i <= end; i++) {
            int temp = prevOne;
            prevOne = max(prevOne, prevTwo + nums[i]);
            prevTwo = temp;
        }
        return prevOne;
    }

public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        return max(helper(nums, 0, nums.size() - 2), helper(nums, 1, nums.size() - 1));
    }
};
