/*
Problem Link: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/

Basic Concept:
 Binary search to find for a number, which after sqauring gives us required num, if found return true, else return false

Time Complexity: O(logn)
*/
class Solution {
public:
    bool isPerfectSquare(long long int num) {
        long long int lower = 1;
        long long int upper = num;
        while(lower <= upper)
        {
            long long int mid = lower + (upper-lower)/2;
            if(mid*mid == num)
                return true;
            else if(mid*mid < num)
            {
                lower = mid + 1;
            }
            else
            {
                upper = mid - 1;
            }
        }
        return false;
    }
};
