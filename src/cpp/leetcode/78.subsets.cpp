/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (50.73%)
 * Total Accepted:    336.9K
 * Total Submissions: 656.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans{vector<int>{}};
        for(int i = 0; i < nums.size(); i++) {
            int size = ans.size();
            for(int j = 0; j < size; j++) {
                vector<int> subset{ans[j]};
                subset.push_back(nums[i]);
                ans.push_back(subset);
            }
        }
        return ans;
    }
};

