/*
20. Dices Sum
中文English
Throw n dices, the sum of the dices' faces is S. Given n, find the all possible value of S along with its probability.

Example
Example 1:

Input: n = 1
Output: [[1, 0.17], [2, 0.17], [3, 0.17], [4, 0.17], [5, 0.17], [6, 0.17]]
Explanation: Throw a dice, the sum of the numbers facing up may be 1, 2, 3, 4, 5, 6, and the probability of each result is 0.17.
Example 2:

Input: n = 2
Output: [[2,0.03],[3,0.06],[4,0.08],[5,0.11],[6,0.14],[7,0.17],[8,0.14],[9,0.11],[10,0.08],[11,0.06],[12,0.03]]
Explanation: Throw two dices, the sum of the numbers facing up may be in [2,12], and the probability of each result is different.
Notice
You do not care about the accuracy of the result, we will help you to output results.
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // Write your code here
        vector<pair<int, double>> ans;
        // dp(2, 2) = dp(1, 1) * dp(1, 1)
        // dp(2, 3) = dp(1, 1) * dp(1, 2) + dp(1, 2) * dp(1, 1)

        for(int j = n; j <= 6*n; j ++) {
            ans.push_back(pair<int, double>{j, helper(n, j)});
        }

        return ans;
    }
    double helper(int n, int sum) {
        if(1 == n) {
            if(sum > 6) return 0.0;
            return (1.0/6.0);
        } else {
            double pro = 0.0;
            for(int j = 1; j < sum; j++) {
                pro += helper(1, j)*helper(n - 1, sum - j);
            }
            return pro;
        }
    }
};