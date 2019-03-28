/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (48.98%)
 * Total Accepted:    243.1K
 * Total Submissions: 491.3K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash(256, 0);
        for(char c:s) {
            hash[c]++;
        }
        for(int i = 0; i < s.length(); i++) {
            if(hash[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

