/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (0 == nums.size())
        {
            return 0;
        }

        unordered_set<int> records(nums.begin(), nums.end());

        int ans = 1;

        for (int n : nums)
        {
            if (records.find(n) == records.end())
            {
                continue;
            }
            records.erase(n);
            int prev = n - 1;
            int next = n + 1;
            while (records.find(prev) != records.end())
            {
                records.erase(prev--);
            }
            while (records.find(next) != records.end())
            {
                records.erase(next++);
            }
            ans = max(ans, next - prev - 1);
        }

        return ans;
    }
};
