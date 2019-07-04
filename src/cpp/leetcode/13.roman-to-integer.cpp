/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
/*
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map({
            {'I', 1}, 
            {'V', 5}, 
            {'X', 10}, 
            {'L', 50}, 
            {'C', 100}, 
            {'D', 500}, 
            {'M', 1000}
            });
        int ans = 0;
        for(int i = 0; i < s.size();) {
            if(i == s.size() - 1) {
                ans += map[s[i]];
                break;
            }
            if(s[i] == 'I' && s[i+1] == 'V') {ans += 4; i+=2;}
            else if(s[i] == 'I' && s[i+1] == 'X') {ans += 9; i+=2;}
            else if(s[i] == 'X' && s[i+1] == 'L') {ans += 40; i+=2;}
            else if(s[i] == 'X' && s[i+1] == 'C') {ans += 90; i+=2;}
            else if(s[i] == 'C' && s[i+1] == 'D') {ans += 400; i+=2;}
            else if(s[i] == 'C' && s[i+1] == 'M') {ans += 900; i+=2;}
            else {ans += map[s[i]]; i++;}
        }
        return ans;
    }
};
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map({
            {'I', 1}, 
            {'V', 5}, 
            {'X', 10}, 
            {'L', 50}, 
            {'C', 100}, 
            {'D', 500}, 
            {'M', 1000}
            });
        int ans = map[s.back()];
        for(int i = s.size() - 2; i >= 0; i--) {
            if(map[s[i]] < map[s[i+1]]) {
                ans -= map[s[i]];
            } else {
                ans += map[s[i]];
            }
        }
        return ans;
    }
};
