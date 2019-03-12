/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (44.52%)
 * Total Accepted:    297.9K
 * Total Submissions: 665K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */
class Solution {
private:
    string strSort(string s) {
        int counter[26] = {0};
        for(char c:s) {
            counter[c - 'a']++;
        }
        string t;
        for(int i = 0; i < 26; i++) {
            t += string(counter[i], i + 'a');
        }
        return t;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s:strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto p:mp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};

