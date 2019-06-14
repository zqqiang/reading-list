/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        auto comp = [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; };
        sort(intervals.begin(), intervals.end(), comp);

        int pre = 0;
        int ans = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < intervals[pre][1])
            {
                ans++;
                if (intervals[i][1] < intervals[pre][1])
                {
                    pre = i;
                }
            }
            else
            {
                pre = i;
            }
        }
        return ans;
    }
};
