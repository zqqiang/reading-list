/*
621. Maximum Subarray V
620. Maximum Subarray IV
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
/*
LintCode
617. Maximum Average Subarray II
Given an array with positive and negative numbers, 
find the maximum average subarray which length should be greater or equal to given length k.

It's guaranteed that the size of the array is greater or equal to k.
Example
Given nums = [1, 12, -5, -6, 50, 3], k = 3

Return 15.667 // (-6 + 50 + 3) / 3 = 15.667
*/
/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/
// todo
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double l = INT_MAX, r = INT_MIN;
        for (int i = 0; i < n; i++) {
            l = min(l, (double)nums[i]);
            r = max(r, (double)nums[i]);
        }
        vector<double> sumNums(n + 1);
        sumNums[0] = 0;
        while (r - l > 1e-6) {
            double mid = (l + r) / 2;
            for (int i = 0; i < n; i++) {
                sumNums[i + 1] = sumNums[i] + nums[i] - mid;
            }
            double preMin = 0;
            double sumMax = INT_MIN;
            for (int i = k; i <= n; i++) {
                sumMax = max(sumMax, sumNums[i] - preMin);
                preMin = min(preMin, sumNums[i - k + 1]);
            }
            if (sumMax >= 0) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};
/*
LintCode
42. Maximum Subarray II
Given an array of integers, find two non-overlapping subarrays which have the largest sum.
The number in each subarray should be contiguous.
Return the largest sum.

The subarray should contain at least one number
Example
Example 1:

Input:
[1, 3, -1, 2, -1, 2]
Output:
7
Explanation:
the two subarrays are [1, 3] and [2, -1, 2] or [1, 3, -1, 2] and [2].
Example 2:

Input:
[5,4]
Output:
9
Explanation:
the two subarrays are [5] and [4].
Challenge
Can you do it in time complexity O(n) ?
*/
class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums) {
        // write your code here
    }
};