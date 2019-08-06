/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int prev1 = 0, prev2 = 0;
        for (auto n : nums) {
            int temp = prev1;
            prev1 = max(prev2 + n, prev1);
            prev2 = temp;
        }
        return prev1;
    }
};
