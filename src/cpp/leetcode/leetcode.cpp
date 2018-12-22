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
LintCode => 213. String Compression
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
451. Sort Characters By Frequency (todo)
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
    }
};
/*
347. Top K Frequent Elements
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
typedef pair<int, int> P;

class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> cnt;
        for (int x : nums)
            cnt[x]++;
        priority_queue<P, vector<P>, greater<P>> q;
        for (auto &x : cnt)
        {
            if (q.size() < k)
                q.push(make_pair(x.second, x.first));
            else
            {
                if (q.top().first < x.second)
                {
                    q.pop();
                    q.push(make_pair(x.second, x.first));
                }
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
/*
LintCode => 471. Top K Frequent Words
Given a list of words and an integer k, return the top k frequent words in the list.

Example
Given

[
    "yes", "lint", "code",
    "yes", "code", "baby",
    "you", "baby", "chrome",
    "safari", "lint", "code",
    "body", "lint", "code"
]
for k = 3, return ["code", "lint", "baby"].

for k = 4, return ["code", "lint", "baby", "yes"],

Challenge
Do it in O(nlogk) time and O(n) extra space.

Notice
You should order the words by the frequency of them in the return list, the most frequent one comes first. If two words has the same frequency, the one with lower alphabetical order come first.
*/
class Solution
{
  public:
    /**
     * @param words: an array of string
     * @param k: An integer
     * @return: an array of string
     */
    vector<string> topKFrequentWords(vector<string> &words, int k)
    {
        // write your code here
        unordered_map<string, int> counts;
        for (const auto &word : words)
        {
            ++counts[word];
        }
        vector<vector<string>> buckets(words.size() + 1);
        for (const auto &kvp : counts)
        {
            buckets[kvp.second].emplace_back(kvp.first);
        }

        vector<pair<int, string>> p;
        for (int i = buckets.size() - 1; i >= 0; --i)
        {
            for (const auto &word : buckets[i])
            {
                p.emplace_back(-i, word);
            }
            if (p.size() >= k)
            {
                break;
            }
        }
        sort(p.begin(), p.end());
        vector<string> result;
        for (int i = 0; i < k; ++i)
        {
            result.emplace_back(p[i].second);
        }
        return result;
    }
};
/*
242. Valid Anagram
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
class Solution
{
  public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        vector<int> vec_freq(26, 0);
        for (int i = 0; i < s.length(); ++i)
        {
            vec_freq[s[i] - 'a']++;
            vec_freq[t[i] - 'a']--;
        }
        for (std::vector<int>::iterator it = vec_freq.begin(); it != vec_freq.end(); ++it)
        {
            if (*it != 0)
            {
                return false;
            }
        }
        return true;
    }
};
/*
LintCode => 158. Valid Anagram
Write a method anagram(s,t) to decide if two strings are anagrams or not.

Example
Given s = "abcd", t = "dcab", return true.
Given s = "ab", t = "ab", return true.
Given s = "ab", t = "ac", return false.

Challenge
O(n) time, O(1) extra space

Clarification
What is Anagram?

Two strings are anagram if they can be the same after change the order of characters.
*/
class Solution
{
  public:
    /**
     * @param s: The first string
     * @param t: The second string
     * @return: true or false
     */
    bool anagram(string &s, string &t)
    {
        // write your code here
        if (s.length() != t.length())
        {
            return false;
        }
        vector<int> vec_freq(57, 0);
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != ' ')
            {
                vec_freq[s[i] - 'A']++;
            }

            if (t[i] != ' ')
            {
                vec_freq[t[i] - 'A']--;
            }
        }
        for (std::vector<int>::iterator it = vec_freq.begin(); it != vec_freq.end(); ++it)
        {
            if (*it != 0)
            {
                return false;
            }
        }
        return true;
    }
};
/*
146. LRU Cache (todos)
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

// capacity
LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);    // returns 1
cache.put(3, 3); // evicts key 2
cache.get(2);    // returns -1 (not found)
cache.put(4, 4); // evicts key 1
cache.get(1);    // returns -1 (not found)
cache.get(3);    // returns 3
cache.get(4);    // returns 4
* /

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

åclass LRUCache
{
  public:
    LRUCache(int capacity) : cacheSize(capacity)
    {
        listSize = 0;
    }
    int get(int key)
    {
        auto it = mapping.find(key);
        if (it == mapping.end())
            return -1;
        itemList.splice(itemList.begin(), itemList, it->second);
        //mapping[key] == it->second still holds
        return it->second->second;
    }
    void put(int key, int value)
    {
        auto it = mapping.find(key);
        if (it != mapping.end())
        {
            itemList.splice(itemList.begin(), itemList, it->second);
            it->second->second = value;
        }
        else
        {
            itemList.push_front(make_pair(key, value));
            ++listSize;
            mapping.insert(make_pair(key, itemList.begin()));
        }
        if (listSize > cacheSize)
        {
            mapping.erase(itemList.back().first);
            --listSize;
            itemList.pop_back();
        }
    }

  private:
    int cacheSize;
    int listSize;
    list<pair<int, int>> itemList;
    unordered_map<int, list<pair<int, int>>::iterator> mapping;
};
/*
543. Diameter of Binary Tree
Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  private:
    int diameter;
    int depth(TreeNode *node)
    {
        if (NULL == node)
            return 0;
        int l = depth(node->left);
        int r = depth(node->right);
        if (this->diameter < l + r + 1)
            this->diameter = l + r + 1;
        return max(l, r) + 1;
    }

  public:
    Solution() : diameter(1){};
    int diameterOfBinaryTree(TreeNode *root)
    {
        depth(root);
        return this->diameter - 1;
    }
};
/*
213. House Robber II (todo)
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have security system connected 
and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/

class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return nums[0];
        }

        return max(robRange(nums, 0, nums.size() - 1), // Include the first one of nums without the last one.
                   robRange(nums, 1, nums.size()));    // Include the last one of nums without the first one.
    }

    int robRange(vector<int> &nums, int start, int end)
    {
        int num_i = nums[start], num_i_1 = 0, num_i_2 = 0;
        for (int i = start + 1; i < end; ++i)
        {
            num_i_2 = num_i_1;
            num_i_1 = num_i;
            num_i = max(nums[i] + num_i_2, num_i_1);
        }
        return num_i;
    }
};
/*
198. House Robber
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that 
adjacent houses have security system connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/
class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        else if (nums.size() == 1)
        {
            return nums[0];
        }
        int num_i = nums[0];
        int num_i_1 = 0;
        int num_i_2 = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            num_i_2 = num_i_1;
            num_i_1 = num_i;
            num_i = max(nums[i] + num_i_2, num_i_1);
        }
        return num_i;
    }
};
/*
139. Word Break
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/
class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (const string &word : wordDict)
            mem_.emplace(word, true);

        return wordBreak(s);
    }

    bool wordBreak(const string &s)
    {
        if (mem_.count(s))
            return mem_[s];

        for (int j = 1; j < s.length(); j++)
        {
            auto it = mem_.find(s.substr(j));
            if (it != mem_.end() && it->second && wordBreak(s.substr(0, j)))
                return mem_[s] = true;
        }

        return mem_[s] = false;
    }

  private:
    unordered_map<string, bool> mem_;
};
/*
123. Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
    }
};
/*
122. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (0 == prices.size())
        {
            return 0;
        }
        int max_profit = 0;
        int buy_price = prices[0];
        int sell_price = 0;
        int start_price = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            if (start_price > prices[i])
            {
                if (sell_price)
                {
                    max_profit += sell_price - buy_price;
                }
                buy_price = prices[i];
                sell_price = 0;
                start_price = buy_price;
            }
            else if (start_price < prices[i])
            {
                sell_price = prices[i];
            }

            start_price = prices[i];
        }
        if (sell_price != 0)
        {
            max_profit += sell_price - buy_price;
        }

        return max_profit;
    }
};
/*
Approach 2: Peak Valley Approach
*/
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int peak = 0;
        int valley = 0;
        int max_profit = 0;
        int len = prices.size();
        int i = 0;

        while (i < len - 1)
        {
            while (i < len - 1 && prices[i] >= prices[i + 1])
            {
                i++;
            }
            valley = prices[i];
            while (i < len - 1 && prices[i] <= prices[i + 1])
            {
                i++;
            }
            peak = prices[i];
            max_profit += peak - valley;
        }

        return max_profit;
    }
};
/*
Approach 3: Simple One Pass
*/
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i - 1] <= prices[i])
            {
                maxprofit += prices[i] - prices[i - 1];
            }
        }
        return maxprofit;
    }
};