/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (27.18%)
 * Total Accepted:    107.1K
 * Total Submissions: 388.6K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if(m+n != s3.size())  return false;
        bool c[n+1] = {true};
        int i, j = 0;
        while(j < n && s2[j] == s3[j]) c[++j] = true;
        for(i = 0; i < m; ++i) {
            c[0] = c[0] & (s1[i] == s3[i]);
            for(j = 1; j <= n; ++j)
                c[j] = ((s1[i] == s3[i+j]) & c[j]) | ((s2[j-1] == s3[i+j]) & c[j-1]);
        }
        return c[n];
    }
};

