/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int left = 0;
        int right = 0;

        for(auto v : intervals) {
            if(v[1] < newInterval[0]) {
                ans.push_back(vector<int>(v));
            } else if (newInterval[1] < v[0]) {
                if(left != right) {
                    ans.push_back(vector<int>{left, right});
                }
                ans.push_back(vector<int>(v));
            } else if (v[1] >= newInterval[0]) {
                left = v[0];
            } else if (newInterval[1] >= v[0] ) {
                right = v[1];
            }
        }
        return ans;
    }
};

