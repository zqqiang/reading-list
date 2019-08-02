/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        return helper(dp, nums, target);
    }
    int helper(vector<int> &dp, vector<int> &nums, int target)
    {
        if (dp[target] != -1) {
            return dp[target];
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target >= nums[i]) {
                ans += helper(dp, nums, target - nums[i]);
            }
        }
        dp[target] = ans;
        return ans;
    }
};
