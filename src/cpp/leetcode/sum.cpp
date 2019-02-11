/*
382. Triangle Count
59. 3Sum Closest
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