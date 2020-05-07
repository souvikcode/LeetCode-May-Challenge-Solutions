/*
Problem Link: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/

The main concept behind this problem:
Store the count of each number of nums in a map, and use this map to return the number which occurs more than 
floor of (length of nums / 2) as the result.

Time Complexity: O(n)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for(int i:nums)
            mp[i]++;
        int result;
        for(auto m:mp)
        {
            if(m.second > (nums.size()-1)/2)
                result = m.first;
        }
        return result;
    }
};
