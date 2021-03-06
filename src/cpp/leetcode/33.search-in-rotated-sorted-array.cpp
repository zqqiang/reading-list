/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            
            while(front < back) {
                int sum = nums[front] + nums[back];
                if(sum < target) {
                    front++;
                } else if(sum > target) {
                    back--;
                } else {
                    vector<int> triple;
                    triple.push_back(nums[i]);
                    triple.push_back(nums[front]);
                    triple.push_back(nums[back]);
                    ans.push_back(triple);
                    
                    while(front < back && nums[front] == triple[1]) front++;
                    while(front < back && nums[back] == triple[2]) back--;
                }
            }
            
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        
        return ans;
    }
};

