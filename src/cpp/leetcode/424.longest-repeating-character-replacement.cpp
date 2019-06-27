/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int res = 0, maxf = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < s.length(); ++i)
        {
            maxf = max(maxf, ++count[s[i]]);
            if (res - maxf < k)
                res++;
            else
                count[s[i - res]]--;
        }
        return res;
    }
};
