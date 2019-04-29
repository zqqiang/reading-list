/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 1) {
            return citations[0] ? 1 : 0;
        }
        int l = 0, r = n - 1;
        int ans = 0;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(citations[mid] >= (n - mid)) {
                ans = max(ans, n - mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

