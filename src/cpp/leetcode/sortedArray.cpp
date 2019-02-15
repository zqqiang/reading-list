/*
212. Space Replacement
6. Merge Two Sorted Arrays
*/
/*
839. Merge Two Sorted Interval Lists (todo)

Description
Merge two sorted (ascending) lists of interval and return it as a new sorted list. 
The new sorted list should be made by splicing together the intervals of the two lists and sorted in ascending order.

The intervals in the given list do not overlap.
The intervals in different lists may overlap.

Example
Example1

Input: list1 = [(1,2),(3,4)] and list2 = [(2,3),(5,6)]
Output: [(1,4),(5,6)]
Explanation:
(1,2),(2,3),(3,4) --> (1,4)
(5,6) --> (5,6)
Example2

Input: list1 = [(1,2),(3,4)] and list2 = [(4,5),(6,7)]
Output: [(1,2),(3,5),(6,7)]
Explanation:
(1,2) --> (1,2)
(3,4),(4,5) --> (3,5)
(6,7) --> (6,7)
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param list1: one of the given list
     * @param list2: another list
     * @return: the new sorted list of interval
     */
    vector<Interval> mergeTwoInterval(vector<Interval> &list1, vector<Interval> &list2) {
        // write your code here
        vector<Interval> result;
        int i = 0, j = 0;
        while (i < list1.size() || j < list2.size()) {
            if (j == list2.size() || (i < list1.size() && list1[i].start <= list2[j].start)) {
                if (result.size() && list1[i].start <= result.back().end) {
                    result.back().end = max(result.back().end, list1[i].end);
                }
                else {
                    result.push_back(list1[i]);
                }
                ++i;
            }
            else {
                if (result.size() && list2[j].start <= result.back().end) {
                    result.back().end = max(result.back().end, list2[j].end);
                }
                else {
                    result.push_back(list2[j]);
                }
                ++j;
            }
        }
        return result;
    }
};