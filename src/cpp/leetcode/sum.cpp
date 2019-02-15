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
LintCode
382. Triangle Count (todo: not pass lintcode)
Description
Given an array of integers, how many three numbers can be found in the array, 
so that we can build an triangle whose three edges length is the three numbers that we find?
Example
Example 1:

Input: [3, 4, 6, 7]
Output: 3
Explanation:
They are (3, 4, 6), 
         (3, 6, 7),
         (4, 6, 7)
Example 2:

Input: [4, 4, 4, 4]
Output: 4
Explanation:
Any three numbers can form a triangle. 
So the answer is C(3, 4) = 4
*/
class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        int ans = 0;
        std::sort(S.begin(), S.end());
        for(int i = 0; i < S.size() - 2; i++) {
            for(int j = i + 1, k = i + 2; k < S.size(); j++) {
                while(k < S.size() && S[i] + S[j] > S[k]) k++;
                if(k > j) ans += (k-j-1);
            }
        }
        return ans;
    }
};
/*
18. 4Sum (todo: learn)
Given an array nums of n integers and an integer target, 
are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target0) {
        vector<vector<int>> result;
        if (num.size() < 4) return result;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            for (int j = i + 1; j < num.size(); j++) {
                int target = target0 - num[i] - num[j];
                int left = j + 1;
                int right = num.size() - 1;
                while (left < right) {
                    int sum = num[left] + num[right];
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        vector<int> four(4,0);
                        four[0] = num[i];
                        four[1] = num[j];
                        four[2] = num[left];
                        four[3] = num[right];
                        result.push_back(four);
                        while (left < right && num[left] == four[2]) left++;
                        while (left < right && num[right] == four[3]) right--;
                    }
                }
                while (j < num.size() - 1 && num[j] == num[j + 1]) j++;
            }
            while (i < num.size() - 1 && num[i] == num[i + 1]) i++;
        }
        return result;
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