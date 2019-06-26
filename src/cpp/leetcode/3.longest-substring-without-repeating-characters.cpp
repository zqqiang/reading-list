/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> mask(256, -1);
        int i = 0, start = -1;
        int ans = 0;
        for (i = 0; i < s.length(); i++)
        {
            if (mask[s[i]] > start)
            {
                start = mask[s[i]];
            }
            mask[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }
};
