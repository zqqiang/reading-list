/*
621. Maximum Subarray V
620. Maximum Subarray IV
617. Maximum Average Subarray II
402. Continuous Subarray Sum
151. Best Time to Buy and Sell Stock III 
43. Maximum Subarray III
*/
/*
944. Maximum Submatrix
Description
Given an n x n matrix of positive and negative integers, find the submatrix with the largest possible sum.
Example
Given matrix = 
[
    [1,3,-1],
    [2,3,-2],
    [-1,-2,-3]
]
return 9.
Explanation:
the submatrix with the largest possible sum is:
[
    [1,3],
    [2,3]
]
*/
class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: the largest possible sum
     */
    int maxSubmatrix(vector<vector<int>> &matrix) {
        
    }
};
/*
643. Maximum Average Subarray I
Given an array consisting of n integers, 
find the contiguous subarray of given length k that has the maximum average value. 
And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 

Note:

1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double ans = sum;
        for(int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i-k];
            ans = std::max(sum, ans);
        }
        return ans/k;
    }
};