/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            int other = target - nums[i];
            if(hash.find(other) != hash.end()) {
                return vector<int> {hash[other], i};
            }
            hash[nums[i]] = i;
        }
        return vector<int> {0};
    }
};

