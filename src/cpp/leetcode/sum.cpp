/*
382. Triangle Count
58. 4Sum
56. Two Sum
*/
/*
LintCode
918. 3Sum Smaller
Description
Given an array of n integers nums and a target, 
find the number of index triplets i, j, k with 0 <= i < j < k < n 
that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Example
Given nums = [-2,0,1,3], target = 2, return 2.

Explanation:
Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]
Challenge
Could you solve it in O(n2) runtime?
*/
class Solution {
public:
    /**
     * @param nums:  an array of n integers
     * @param target: a target
     * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
     */
    int threeSumSmaller(vector<int> &nums, int target) {
        // Write your code here
        if (nums.size() < 3) {
            return 0;
        }
        int ans = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                if (nums[i] + nums[j] + nums[k] < target) {
                    ans += (k - j);
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};
/*
16. 3Sum Closest
Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min = INT_MAX;
        int ans = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < min) {
                    min = abs(sum - target);
                    ans = sum;
                }
                if (sum - target > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};