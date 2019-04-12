/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (27.31%)
 * Total Accepted:    68.5K
 * Total Submissions: 244.2K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 * 
 * Example:
 * 
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * 
 * Note:
 * 
 * 
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 * 
 * 
 */

// todo: not pass
class NumArray {
private:
    vector<int> tree;
    int n;

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(2*n, 0);
        for(int i = n, j = 0; i < 2*n; i++, j++) {
            tree[i] = nums[j];
        }
        for(int i = n - 1; i > 0; i--) {
            tree[i] = tree[2*i] + tree[2*i + 1];
        }
    }
    
    void update(int i, int val) {
        int pos = n + i;
        tree[pos] = val;
        while(pos) {
            int left, right;
            if(pos%2 == 0) {
                right = pos + 1;
            } else {
                left = pos - 1;
            }
            pos = pos/2;
            tree[pos] = tree[left] + tree[right];            
        }
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        int left = n + i;
        int right = n + j;
        while(left <= right) {
            if(left%2 == 1) {
                sum += tree[left];
                left++;
            }
            if(right%2 == 1) {
                sum += tree[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
