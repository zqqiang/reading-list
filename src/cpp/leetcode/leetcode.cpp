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
632. Smallest Range (todos)
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
        bool flag = true;
        int minx = 0, miny = INT_MAX;
        vector<int> next(nums.size(), 0);

        for (int i = 0; i < nums.size() && flag; ++i)
        {
            for (int j = 0; j < nums[i].size() && flag; ++j)
            {
                int min_i = 0;
                int max_i = 0;

                for (int k = 0; k < nums.size(); ++k)
                {
                    if (nums[min_i][next[min_i]] > nums[k][next[k]])
                    {
                        min_i = k;
                    }
                    if (nums[max_i][next[max_i]] > nums[k][next[k]])
                    {
                        max_i = k;
                    }
                }

                if (miny - minx > nums[max_i][next[max_i]] - nums[min_i][next[min_i]])
                {
                    miny = nums[max_i][next[max_i]];
                    minx = nums[min_i][next[min_i]];
                }

                next[min_i]++;

                if (next[min_i] == nums[min_i].size())
                {
                    flag = false;
                }
            }
        }
        return vector<int>{minx, miny};
    }
};

/*
443. String Compression
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

 
Follow up:
Could you solve it using only O(1) extra space?

 
Example 1:

Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
 

Example 2:

Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
 

Example 3:

Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
 

Note:

All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.
*/

class Solution
{
  public:
    int compress(vector<char> &chars)
    {
        int total = 0;
        std::vector<char>::iterator cur_it = chars.begin();

        for (std::vector<char>::iterator it = chars.begin(); it != chars.end();)
        {
            char last = *it;
            int count = 0;
            total++;
            for (; it != chars.end() && *it == last; it++)
            {
                count++;
            }
            if (count != 1)
            {
                *cur_it++ = last;
                std::string count_str = std::to_string(count);
                for (int i = 0; i < count_str.size(); i++)
                {
                    *cur_it++ = count_str[i];
                }
                total += count_str.size();
            }
            else
            {
                *cur_it++ = last;
            }
        }
        return total;
    }
};

/*
Lintcode => 213. String Compression
Description
Implement a method to perform basic string compression using the counts of repeated characters. 
For example, the string aabcccccaaa would become a2b1c5a3.

If the "compressed" string would not become smaller than the original string, your method should return the original string.

You can assume the string has only upper and lower case letters (a-z).

Example
str=aabcccccaaa return a2b1c5a3
str=aabbcc return aabbcc
str=aaaa return a4
*/
class Solution
{
  public:
    /**
     * @param originalString: a string
     * @return: a compressed string
     */
    string compress(string &originalString)
    {
        // write your code here
        int total = 0;
        std::string::iterator cur_it = originalString.begin();
        std::string result_str;

        for (std::string::iterator it = originalString.begin(); it != originalString.end();)
        {
            char last = *it;
            int count = 0;
            total++;
            for (; it != originalString.end() && *it == last; it++)
            {
                count++;
            }

            result_str.push_back(last);
            std::string count_str = std::to_string(count);
            for (int i = 0; i < count_str.size(); i++)
            {
                result_str.push_back(count_str[i]);
            }
            total += count_str.size();
        }
        if (total >= originalString.size())
        {
            return originalString;
        }
        else
        {
            return result_str;
        }
    }
};
/*
167. Two Sum II - Input array is sorted
Given an array of integers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/
class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        std::vector<int>::iterator last_it = numbers.begin();
        for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        {
            if (last_it != numbers.begin())
            {
                if (*last_it == *it)
                {
                    continue;
                }
            }
            last_it = it;
            for (std::vector<int>::iterator next_it = it + 1; next_it != numbers.end(); next_it++)
            {
                if (*it + *next_it == target)
                {
                    return vector<int>{it - numbers.begin() + 1, next_it - numbers.begin() + 1};
                }
            }
        }
        return vector<int>{0, 0};
    }
};

/*
121. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0;
        int min_price = INT_MAX;
        for (std::vector<int>::iterator it = prices.begin(); it != prices.end(); it++)
        {
            if (min_price > *it)
            {
                min_price = *it;
            }
            else if (max_profit < *it - min_price)
            {
                max_profit = *it - min_price;
            }
        }
        return max_profit;
    }
};
/*
451. Sort Characters By Frequency
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
class Solution
{
  public:
    string frequencySort(string s)
    {
        struct counter
        {
            char s;
            unsigned int count;
        };

        vector<struct counter> vec_counter;

        for (std::string::iterator it = s.begin(); it != s.end(); ++it)
        {
            for (std::vector::iterator v_it = vec_counter.begin(); v_it != vec_counter.end(); ++v_it)
            {
                if (*v_it.s == *it)
                {
                    *v_it.count++;
                }
                else
                {
                    vec_counter.push_back({*it, 0});
                }
            }
        }

        bool comp(struct counter i, struct counter j)
        {
            return i.count > j.count;
        }

        std::sort(vec_counter.begin(), vec_counter.end(), comp)
    }
};