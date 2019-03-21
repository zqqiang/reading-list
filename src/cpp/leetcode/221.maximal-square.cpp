/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (32.16%)
 * Total Accepted:    118.2K
 * Total Submissions: 366.9K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */
class Solution
{
  public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int rows = matrix.size();
        int cols = rows ? matrix[0].size() : 0;
        vector<int> dp(cols, 0);
        int prev = 0;
        int maxsqlen = 0;
        
        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= cols; j++) {
                int temp = dp[j];
                if(matrix[i-1][j-1] == '1') {
                    dp[j] = std::min(std::min(prev, dp[j-1]), dp[j]) + 1;
                    maxsqlen = std::max(maxsqlen, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        
        return maxsqlen * maxsqlen;
    }
};
