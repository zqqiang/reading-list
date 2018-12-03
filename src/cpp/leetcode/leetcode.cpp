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
        int max = 0;
        int index = 0;
        int max_index = 0;
        int next = num;
        int cur = 0;

        while (next)
        {
            cur = next % 10;
            if (max < cur)
            {
                max = cur;
                max_index = index;
            }
            next = next / 10;
            index++;
        }

        if (max_index == index - 1)
        {
            if (index == 1)
            {
                return num;
            }
            int top = num / pow(10, index - 1);
            return top * pow(10, index - 1) + maximumSwap(top / pow(10, index - 1));
        }

        return num - max * pow(10, max_index) - cur * pow(10, index - 1) + max * pow(10, index - 1) + cur * pow(10, max_index);
    }
};