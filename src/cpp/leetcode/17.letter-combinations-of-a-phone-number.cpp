/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (40.22%)
 * Total Accepted:    352.8K
 * Total Submissions: 870.2K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
private:
    vector<string> ans;
    vector<string> map{
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    void back_track(string combination, string next_digits) {
        if(next_digits.length() == 0) {
            ans.push_back(combination);
        } else {
            string digit = next_digits.substr(0, 1);
            int index = std::stoi(digit);
            string letters = map[index - 2];
            for(int i = 0; i < letters.length(); i++) {
                string letter = letters.substr(i, 1);
                back_track(combination + letter, next_digits.substr(1));
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() != 0) {
            back_track("", digits);
        }
        return ans;
    }
};

