/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;
        
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        
        return result;
    }
};

