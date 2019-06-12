/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */
class Solution
{
private:
    void dfs(vector<vector<int>> &m, int i, int j, int h, vector<vector<bool>> &v) //h: height, v for visited
    {
        int r = m.size();
        int c = m[0].size();
        if (i < 0 || j < 0 || i >= r || j >= c || m[i][j] < h || v[i][j])
            return;
        h = m[i][j];
        v[i][j] = true;
        dfs(m, i - 1, j, h, v);
        dfs(m, i + 1, j, h, v);
        dfs(m, i, j - 1, h, v);
        dfs(m, i, j + 1, h, v);
        return;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &m)
    {
        vector<vector<int>> res;
        if (m.empty())
            return res;
        int r = m.size();
        int c = m[0].size();
        vector<vector<bool>> pacific(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic(r, vector<bool>(c, false)); //store visited
        for (int i = 0; i < r; i++)
        {
            dfs(m, i, 0, -1, pacific);
            dfs(m, i, c - 1, -1, atlantic);
        }
        for (int j = 0; j < c; j++)
        {
            dfs(m, 0, j, -1, pacific);
            dfs(m, r - 1, j, -1, atlantic);
        }
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
        return res;
    }
};
