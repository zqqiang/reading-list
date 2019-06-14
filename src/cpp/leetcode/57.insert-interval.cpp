/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int index = 0;
        while (index < intervals.size() && intervals[index][1] < newInterval[0])
        {
            ans.push_back(intervals[index++]);
        }
        while (index < intervals.size() && intervals[index][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            index++;
        }
        ans.push_back(newInterval);
        while (index < intervals.size())
        {
            ans.push_back(intervals[index++]);
        }
        return ans;
    }
};
