/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (29.97%)
 * Total Accepted:    63.7K
 * Total Submissions: 209.7K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in
 * the given list, so that the concatenation of the two words, i.e. words[i] +
 * words[j] is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]] 
 * Explanation: The palindromes are
 * ["dcbaabcd","abcddcba","slls","llssssll"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["bat","tab","cat"]
 * Output: [[0,1],[1,0]] 
 * Explanation: The palindromes are ["battab","tabbat"]
 * 
 * 
 * 
 * 
 */
class Solution
{
  public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        unordered_map<string, int> dict;
        vector<vector<int>> ans;
        // build dictionary
        for (int i = 0; i < words.size(); i++)
        {
            string key = words[i];
            reverse(key.begin(), key.end());
            dict[key] = i;
        }
        // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
        if (dict.find("") != dict.end())
        {
            for (int i = 0; i < words.size(); i++)
            {
                if (i == dict[""])
                    continue;
                if (isPalindrome(words[i]))
                    ans.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self)
            }
        }

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size() - j);

                if (dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i)
                {
                    ans.push_back({i, dict[left]}); // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
                }

                if (dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i)
                {
                    ans.push_back({dict[right], i});
                }
            }
        }

        return ans;
    }

    bool isPalindrome(string str)
    {
        int i = 0;
        int j = str.size() - 1;

        while (i < j)
        {
            if (str[i++] != str[j--])
                return false;
        }

        return true;
    }
};
