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
123. Best Time to Buy and Sell Stock III (todo)
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
        int buy1 = INT_MAX;
        int buy2 = INT_MAX;
        int sell1 = 0;
        int sell2 = 0;

        for (int i = 0; i < prices.size(); ++i)
        {
            buy1 = std::min(buy1, prices[i]);
            sell1 = std::max(sell1, prices[i] - buy1);
            buy2 = std::min(buy2, prices[i] - sell1);
            sell2 = std::max(sell2, prices[i] - buy2);
        }

        return sell2;
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
/*
295. Find Median from Data Stream
Median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
*/
class MedianFinder
{
  private:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;

  public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        lo.push(num);

        hi.push(lo.top());
        lo.pop();

        if (lo.size() < hi.size())
        {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian()
    {
        return (lo.size() > hi.size() ? (double)lo.top() : (lo.top() + hi.top()) * 0.5);
    }
};

/*
81. Find Median from Data Stream - LintCode
Description
Numbers keep coming, return the median of numbers at every time a new number added.

Have you met this question in a real interview?  
Clarification
What's the definition of Median?

Median is the number that in the middle of a sorted array. 
If there are n numbers in a sorted array A, the median is A[(n - 1) / 2]. 
For example, if A=[1,2,3], median is 2. If A=[1,19], median is 1.

Example
For numbers coming list: [1, 2, 3, 4, 5], return [1, 1, 2, 2, 3].

For numbers coming list: [4, 5, 1, 3, 2, 6, 0], return [4, 4, 4, 3, 3, 3, 3].

For numbers coming list: [2, 20, 100], return [2, 2, 20].

Challenge
Total run time in O(nlogn).
*/

class Solution
{
  private:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
    vector<int> result;

  public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums)
    {
        // write your code here
        for (int i = 0; i < nums.size(); ++i)
        {
            lo.push(nums[i]);

            hi.push(lo.top());
            lo.pop();

            if (lo.size() < hi.size())
            {
                lo.push(hi.top());
                hi.pop();
            }

            result.push_back(lo.top());
        }
        return result;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
/*
236. Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q 
as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
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
    TreeNode *ans;

    bool recurseTree(TreeNode *current, TreeNode *p, TreeNode *q)
    {
        if (NULL == current)
        {
            return false;
        }

        int right = recurseTree(current->right, p, q) ? 1 : 0;
        int left = recurseTree(current->left, p, q) ? 1 : 0;
        int mid = (current == p || current == q) ? 1 : 0;

        if (left + right + mid >= 2)
        {
            this->ans = current;
        }

        return (left + right + mid > 0);
    }

  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        this->recurseTree(root, p, q);
        return this->ans;
    }
};
/*
88. Lowest Common Ancestor of a Binary Tree
Description
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.

The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

Assume two nodes are exist in tree.

Have you met this question in a real interview?  
Example
For the following binary tree:

  4
 / \
3   7
   / \
  5   6
LCA(3, 5) = 4

LCA(5, 6) = 7

LCA(6, 7) = 7
*/
class Solution
{
  private:
    TreeNode *ans;

    bool recurseTree(TreeNode *current, TreeNode *p, TreeNode *q)
    {
        if (NULL == current)
        {
            return false;
        }

        if (current == p && current == q)
        {
            this->ans = current;
            return true;
        }

        int right = recurseTree(current->right, p, q) ? 1 : 0;
        int left = recurseTree(current->left, p, q) ? 1 : 0;
        int mid = (current == p || current == q) ? 1 : 0;

        if (left + right + mid >= 2)
        {
            this->ans = current;
        }

        return (left + right + mid > 0);
    }

  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        this->recurseTree(root, p, q);
        return this->ans;
    }
};
/*
215. Kth Largest Element in an Array
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> q;
        for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            q.push(*it);
        }
        for (int i = 1; i < k; ++i)
        {
            q.pop();
        }
        return q.top();
    }
};
/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/
/*
lintCode solution (todo)
*/
class Solution
{
  public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums)
    {
        if (nums.size() == 0 || k < 1 || k > nums.size())
        {
            return -1;
        }
        return partition(nums, 0, nums.size() - 1, nums.size() - k);
    }

  private:
    int partition(vector<int> &nums, int start, int end, int k)
    {
        if (start >= end)
        {
            return nums[k];
        }

        int left = start, right = end;
        int pivot = nums[(start + end) / 2];

        while (left <= right)
        {
            while (left <= right && nums[left] < pivot)
            {
                left++;
            }
            while (left <= right && nums[right] > pivot)
            {
                right--;
            }
            if (left <= right)
            {
                swap(nums, left, right);
                left++;
                right--;
            }
        }

        if (k <= right)
        {
            return partition(nums, start, right, k);
        }
        if (k >= left)
        {
            return partition(nums, left, end, k);
        }
        return nums[k];
    }

    void swap(vector<int> &nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
/*
162. Find Peak Element
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
Note:

Your solution should be in logarithmic complexity.
*/
class Solution
{
  public:
    int findPeakElement(vector<int> &nums)
    {
        int len = nums.size();
        for (int i = 1; i < len - 1; ++i)
        {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
            {
                return i;
            }
        }
        return nums[0] > nums[len - 1] ? 0 : len - 1;
    }
};
/*
75. Find Peak Element
Description
There is an integer array which has the following features:

The numbers in adjacent positions are different.
A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
We define a position P is a peak if:

A[P] > A[P-1] && A[P] > A[P+1]
Find a peak element in this array. Return the index of the peak.

It's guaranteed the array has at least one peak.
The array may contain multiple peeks, find any of them.
The array has at least 3 numbers in it.
Have you met this question in a real interview?  
Example
Given [1, 2, 1, 3, 4, 5, 7, 6]

Return index 1 (which is number 2) or 6 (which is number 7)

Challenge
Time complexity O(logN)
*/
class Solution
{
  public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 1;
        int r = nums.size();

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            if (nums[mid] > nums[mid - 1])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return -1;
    }
};
/*
89. Gray Code (todo)
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, 
print the sequence of gray code. A gray code sequence must begin with 0.

Example 1:

Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1
Example 2:

Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0.
             A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
             Therefore, for n = 0 the gray code sequence is [0].
*/
class Solution
{
  public:
    vector<int> grayCode(int n)
    {
        vector<int> ans = {0};
        for (int i = 1; i <= n; ++i)
        {
            int x = 1 << (i - 1); // x = 2^(i-1)
            for (int j = 0; j < x; ++j)
            {
                ans.push_back(ans[x - 1 - j] + x);
            }
        }
        return ans;
    }
};
/*
75. Sort Colors
Given an array with n objects colored red, white or blue, 
sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, 
then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int anchor = 0;

        while (low < high && anchor <= high)
        {
            if (nums[anchor] == 0)
            {
                swap(nums[low], nums[anchor]);
                low++;
                anchor++;
            }
            else if (nums[anchor] == 1)
            {
                anchor++;
            }
            else
            {
                swap(nums[anchor], nums[high]);
                high--;
            }
        }
    }
};
/*
66. Plus One
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, 
and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/
class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        int inc = 1;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            inc = (digits[i] + inc) / 10;
            digits[i] = (digits[i] + 1) % 10;
            if (0 == inc)
                return digits;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
/*
57. Insert Interval
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
  public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
    {
    }
};
/*
50. Pow(x, n)
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/
class Solution
{
  public:
    double myPow(double value, int pow)
    {
        double result = 1;
        if (pow < 0)
            value = 1 / value;
        while (pow != 0)
        {
            if (pow % 2)
                result *= value;
            value *= value;
            pow /= 2;
        }
        return result;
    }
};
/*
48. Rotate Image (todo)
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, 
which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/
class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n <= 1)
            return;
        for (int i = 0; i < (n + 1) / 2; ++i)
        {
            for (int j = 0; j < n / 2; ++j)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};
/*
39. Combination Sum (todo)
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

class Solution
{
  public:
    void combinationSum(vector<vector<int>> &res, vector<int> &c, vector<int> s, int target, int idx)
    {
        if (target == 0)
            res.push_back(s);
        else if (idx >= c.size() || c[idx] > target)
            return;
        else
        {
            combinationSum(res, c, s, target, idx + 1);
            s.push_back(c[idx]);
            combinationSum(res, c, s, target - c[idx], idx);
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        sort(begin(candidates), end(candidates));
        combinationSum(res, candidates, vector<int>() = {}, target, 0);
        return res;
    }
};
/*
LintCode
135. Combination Sum
Description
Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Have you met this question in a real interview?  
Example
Given candidate set [2,3,6,7] and target 7, a solution set is:

[7]
[2, 2, 3]
*/
/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution
{
  private:
    const int index_count;
    vector<vector<int>> results;

  public:
    Solution() : index_count(10000){};
    void backtrace(int target, int sum, vector<int> &candidates, int index[], int n)
    {
        if (sum > target)
        {
            return;
        }
        if (sum == target)
        {
            vector<int> result;
            for (int i = 1; i <= n; ++i)
            {
                result.push_back(candidates[index[i]]);
            }
            results.push_back(result);
            return;
        }
        for (int i = index[n]; i < candidates.size(); ++i)
        {
            index[n + 1] = i;
            backtrace(target, sum + candidates[i], candidates, index, n + 1);
        }
    }
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // write your code here
        sort(candidates.begin(), candidates.end());
        int m = 0, n = candidates.size();
        for (int i = 1; i < n; ++i)
            if (candidates[i] != candidates[m])
                candidates[++m] = candidates[i];
        candidates.resize(m + 1);

        int *index = new int[index_count];
        memset(index, 0, sizeof(int) * index_count);

        results.clear();
        backtrace(target, 0, candidates, index, 0);

        delete[] index;

        return results;
    }
};
/*
34. Find First and Last Position of Element in Sorted Array (todo)
Given an array of integers nums sorted in ascending order, 
find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int lo = 0;
        int hi = nums.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        if (lo == nums.size() || nums[lo] != target)
        {
            return {-1, -1};
        }
        int left = lo;
        hi = nums.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        int right = lo - 1;
        return {left, right};
    }
};
/*
33. Search in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
class Solution
{
  private:
    int find(vector<int> &nums, int l, int r, int target)
    {
        int m = l + (r - l) / 2;
        if (l > r)
        {
            return -1;
        }
        if (nums[m] == target)
        {
            return m;
        }
        if (nums[l] <= nums[m])
        {
            if (nums[l] <= target && target <= nums[m])
            {
                return find(nums, l, m, target);
            }
            else
            {
                return find(nums, m + 1, r, target);
            }
        }
        else
        {
            if (nums[m] <= target && target <= nums[r])
            {
                return find(nums, m, r, target);
            }
            else
            {
                return find(nums, l, m - 1, target);
            }
        }
    }

  public:
    int search(vector<int> &nums, int target)
    {
        return find(nums, 0, nums.size() - 1, target);
    }
};
/*
23. Merge k Sorted Lists
Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
    }
};
/*
22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
class Solution
{
  private:
    vector<string> str;

    void process(string s, int open, int close)
    {
        if (open == 0 && close == 0)
        {
            str.push_back(s);
            return;
        }

        if (open > 0)
        {
            process(s + "(", open - 1, close + 1);
        }
        if (close > 0)
        {
            process(s + ")", open, close - 1);
        }

        return;
    }

  public:
    vector<string> generateParenthesis(int n)
    {
        string s = "";
        process(s, n, 0);
        return str;
    }
};
/*
21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (NULL == l1 && NULL == l2)
            return NULL;
        if (NULL == l1)
            return l2;
        if (NULL == l2)
            return l1;
        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
/*
4. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
    }
};
/*
385. Mini Parser
Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces. + 
String contains only digits 0-9, [, - ,, ].
Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
*/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
  public:
    NestedInteger deserialize(string s)
    {
    }
};
/*
155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
class MinStack
{
  private:
    vector<int> stack;
    vector<int> min_stack;

  public:
    /** initialize your data structure here. */
    MinStack()
    {
        min_stack.push_back(INT_MAX);
    }

    void push(int x)
    {
        stack.push_back(x);
        if (min_stack.back() > x)
        {
            min_stack.push_back(x);
        }
        else
        {
            min_stack.push_back(min_stack.back());
        }
    }

    void pop()
    {
        stack.pop_back();
        min_stack.pop_back();
    }

    int top()
    {
        return stack.back();
    }

    int getMin()
    {
        return min_stack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
/*
95. Unique Binary Search Trees II (todo)
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
  public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generate(int beg, int end)
    {
        vector<TreeNode *> ret;
        if (beg > end)
        {
            ret.push_back(NULL);
            return ret;
        }

        for (int i = beg; i <= end; i++)
        {
            vector<TreeNode *> leftTree = generate(beg, i - 1);
            vector<TreeNode *> rightTree = generate(i + 1, end);
            for (int j = 0; j < leftTree.size(); j++)
                for (int k = 0; k < rightTree.size(); k++)
                {
                    TreeNode *node = new TreeNode(i + 1);
                    ret.push_back(node);
                    node->left = leftTree[j];
                    node->right = rightTree[k];
                }
        }

        return ret;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        // write your code here
        return generate(0, n - 1);
    }
};
/*
20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/
class Solution
{
  public:
    bool isValid(string s)
    {
        vector<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case '(':
                st.push_back(')');
                break;
            case '[':
                st.push_back(']');
                break;
            case '{':
                st.push_back('}');
                break;
            case ')':
            case ']':
            case '}':
                if (st.size() == 0 || st[st.size() - 1] != s[i])
                    return false;
                st.pop_back();
                break;
            default:
                break;
            }
        }
        if (st.size() != 0)
            return false;
        return true;
    }
};
/*
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. 
Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int len = height.size();
        int ans = 0;
        
        for (int i = 1; i < len - 1; i++) {
            int max_left = 0;
            int max_right = 0;
            for (int l = 0; l <= i; l++) {
                if (max_left < height[l]) {
                    max_left = height[l];
                }
            }
            for (int r = i; r < len; r++) {
                if (max_right < height[r]) {
                    max_right = height[r];
                }
            }
            ans += min(max_left, max_right) - height[i];
        }
        
        return ans;
    }
};
/*
Approach 2: Dynamic Programming
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        
        int size = height.size();
        if (size == 0) {
            return 0;
        }
        
        vector<int> max_left(size);
        vector<int> max_right(size);
        
        max_left[0] = height[0];
        for (int l = 1; l < size; l++) {
            max_left[l] = max(max_left[l - 1], height[l]);
        }
        
        max_right[size - 1] = height[size - 1];
        for (int r = size - 2; r >= 0; r--) {
            max_right[r] = max(max_right[r + 1], height[r]);
        }
        
        for (int i = 1; i < size - 1; i++) {
            ans += min(max_left[i], max_right[i]) - height[i];
        }
        
        return ans;
    }
};
/*
94. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
/*
Approach 1: Recursive Approach
*/
class Solution {
private:
    void helper(TreeNode *node, vector<int> &res) {
        if (node) {
            if (node->left) {
                helper(node->left, res);
            }
            res.push_back(node->val);
            if (node->right) {
                helper(node->right, res);
            }
        }
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};
/*
Approach 2: Iterating method using Stack
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while(cur || !s.empty()) {
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};
/*
Approach 3: Morris Traversal (todo)
*/

/*
398. Random Pick Index
Given an array of integers with possible duplicates, 
randomly output the index of a given target number. 
You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
*/
class Solution {
private:
    vector<int> _nums;

public:
    Solution(vector<int> nums) {
        _nums = nums;
    }
    
    int pick(int target) {
        int n = 0;
        int index = 0;
        for (int i = 0; i < _nums.size(); i++) {
            if (_nums[i] != target) continue;
            if (0 == n) {
                index = i;
                n++;
            } else {
                n++;
                if (rand()%n == 0) {
                    index = i;
                }
            }
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
/*
103. Binary Tree Zigzag Level Order Traversal (todo)
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        zigzagHelper(root, 0, ret);
        return ret;
    }
    
    void zigzagHelper(TreeNode* root, int level, vector<vector<int>>& ret)
    {
        if(root == NULL) return;
        
        if(ret.size() <= level) ret.push_back(vector<int>());
        
        zigzagHelper(root->left, level+1, ret);
        
        if(level % 2 == 0) ret[level].push_back(root->val);
        else ret[level].insert(ret[level].begin(), root->val);
        
        zigzagHelper(root->right, level+1, ret);        
    }
        
};

/*
102. Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
class Solution {
private:
    void helper(TreeNode* node, int level, vector<vector<int>>& ans) {
        if (NULL == node) {
            return;
        }
        
        if (ans.size() <= level) {
            ans.push_back(vector<int>{});
        }
        
        helper(node->left, level + 1, ans);
        
        ans[level].push_back(node->val);
        
        helper(node->right, level + 1, ans);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root, 0, ans);
        return ans;
    }
};
/*
4ms C++ solution using one queue (todos)
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> level;
        TreeNode* temp;
        int node_num=0;  
        int leaf_num=1;
        
        if(!root) {
            return result;
        }
        
        queue<TreeNode* > tree_queue;
        tree_queue.push(root);
        
        while(!tree_queue.empty()) {
            temp=tree_queue.front();
            level.push_back(temp->val);
            tree_queue.pop();
            leaf_num=leaf_num-1;
            if(temp->left) {
                tree_queue.push(temp->left);
                node_num++;
            }
            if(temp->right) {
                tree_queue.push(temp->right);
                node_num++;
            }
            if(leaf_num==0) {
                result.push_back(level);
                leaf_num=node_num;
                node_num=0;
                level.clear();
            }
        }
        return result;
    }
};
/*
101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
/*
Approach 1: Recursive (todo)
*/
class Solution {
private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        if (left == NULL || right == NULL) {
            return false;
        }
        return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};
/*
98. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
*/
class Solution {
public:
    bool check(TreeNode* root,long long int min,long long int max)
    {
         if(root==NULL)
         {
             return true;
         }
         if(root->val<max&&root->val>min)
         {
             return check(root->left,min,root->val)&&check(root->right,root->val,max);
         }
         return false;
    }
    bool isValidBST(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        return check(root,INT64_MIN,INT64_MAX);
    }
};
/*
119. Pascal's Triangle II
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        unsigned long tmp;
        for(int i=1;i<rowIndex+1;i++)
        {
            tmp=(unsigned long)res[i-1]*(rowIndex-i+1)/i;
            res.push_back(tmp);
        }
        return res;
    }
};