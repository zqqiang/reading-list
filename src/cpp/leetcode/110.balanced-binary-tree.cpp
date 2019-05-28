/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool checkBalance(TreeNode *root, int &height)
    {
        if (!root)
        {
            height = 0;
            return true;
        }
        int leftHeight = 0;
        int rightHeight = 0;
        if (!checkBalance(root->left, leftHeight))
            return false;

        if (!checkBalance(root->right, rightHeight))
            return false;

        if (abs(leftHeight - rightHeight) > 1)
            return false;
        height = max(leftHeight, rightHeight) + 1;
        return true;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        int height = 0;
        return checkBalance(root, height);
    }
};
