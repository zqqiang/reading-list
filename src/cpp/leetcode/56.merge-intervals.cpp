/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (!intervals.size()) return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if(ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};

