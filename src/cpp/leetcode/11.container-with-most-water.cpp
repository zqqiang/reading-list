/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int water = 0;
        while(i < j) {
            int minHeight = min(height[i], height[j]);
            int width = j - i;
            water = max(water, minHeight * width);
            while(height[i] <= minHeight && i < j) i++;
            while(height[j] <= minHeight && i < j) j--;
        }
        return water;
    }
};

