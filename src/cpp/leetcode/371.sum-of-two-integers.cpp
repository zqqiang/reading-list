/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */
class Solution {
public:
    int getSum(int a, int b) {
        int c;
        while(b != 0) {
            c = a & b;
            a = a ^ b;
            b = (c & 0xffffffff) << 1;
        }
        return a;
    }
};

