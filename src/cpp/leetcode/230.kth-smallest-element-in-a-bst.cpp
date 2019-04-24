/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode *root, int k)
    {
        // Inorder traversal
        recur(root, k);
        return rst;
    }

    void recur(TreeNode *root, int &k)
    {
        if (!root)
            return;

        recur(root->left, k);

        if (k == 1)
        {
            rst = root->val;
        }
        k = k - 1;

        recur(root->right, k);
    }

    int rst;
};
