#include <math>
/*
670. Maximum Swap

Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]
Accepted
30,165
Submissions
77,309
*/
class Solution
{
  public:
    /**
     * @param num: a non-negative intege
     * @return: the maximum valued number
     */
    int maximumSwap(int num)
    {
        // Write your code here
        int last[8] = {0};
        int index = 0;
        int calc = num;

        while (calc)
        {
            last[index++] = calc % 10;
            calc = calc / 10;
        }

        for (int i = index - 1; i >= 0; --i)
        {
            for (int j = 9; j > last[i]; --j)
            {
                for (int t = 0; t < i; ++t)
                {
                    if (last[t] == j)
                    {
                        int temp = last[i];
                        last[i] = j;
                        last[t] = temp;

                        int result = 0;
                        for (int m = 0; m <= index - 1; ++m)
                        {
                            result += last[m] * pow(10, m);
                        }
                        return result;
                    }
                }
            }
        }
        return num;
    }
};
/*
697. Degree of an Array
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/

class Solution
{
  public:
    int findShortestSubArray(vector<int> &nums)
    {
        std::map<int, int> left;
        std::map<int, int> right;
        std::map<int, int> count;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (left.find(nums[i]) == left.end())
            {
                left[nums[i]] = i;
            }
            right[nums[i]] = i;
            count[nums[i]] += 1;
        }

        int degree = 0;
        for (std::map<int, int>::iterator it = count.begin(); it != count.end(); ++it)
        {
            if (degree < it->second)
            {
                degree = it->second;
            }
        }

        int result = 50000;
        for (std::map<int, int>::iterator it = count.begin(); it != count.end(); ++it)
        {
            if (it->second == degree)
            {
                result = min(result, right[it->first] - left[it->first] + 1);
            }
        }
        return result;
    }
};

/*
632. Smallest Range
You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Note:
The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.
For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.
*/

class Solution
{
  public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int left = 100000;
        int right = -100000;

        for (std::vector<vector<int>>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            int first = it->front();
            if (left > first)
            {
                left = first;
            }
            int last = it->back();
            if (right < last)
            {
                right = last;
            }
        }
        return vector<int>{left, right};
    }
};