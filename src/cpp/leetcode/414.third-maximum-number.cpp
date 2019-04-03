/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (28.61%)
 * Total Accepted:    87.3K
 * Total Submissions: 303.3K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int res;
        int a, b, c;
        bool min_flag=0;
        a=b=c=INT_MIN;
        for(auto num : nums) {
            if(num==INT_MIN) min_flag=1;
            if(num==a || num==b || num==c) continue;
            if(num>c) c=num;
            if(c>b) swap(c, b);
            if(b>a) swap(b, a);
        }
        res = min_flag?((b==INT_MIN)?a:c):((c==INT_MIN)?a:c);
        return res;
    }
};

