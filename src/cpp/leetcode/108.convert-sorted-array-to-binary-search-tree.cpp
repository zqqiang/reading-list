/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (49.07%)
 * Total Accepted:    235.8K
 * Total Submissions: 480.5K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
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
    TreeNode* helper(vector<int>& nums, int low, int high) {
        if(low > high) {
            return NULL;
        }
        int mid = (low + high) / 2;
        TreeNode* midNode = new TreeNode(nums[mid]);
        midNode->left = helper(nums, low, mid-1);
        midNode->right = helper(nums, mid+1, high);
        return midNode;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(0 == nums.size()) {
            return NULL;
        }
        return helper(nums, 0, nums.size()-1);
    }
};
