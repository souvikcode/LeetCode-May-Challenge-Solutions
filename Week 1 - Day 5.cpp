/*
Problem Link : https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/

The main concept behind this problem is:
 We need to keep count of each character which are in s, and return the first occurrence of non-repeating character.To keep count, we will use map in C++, it will keep count of each character through one traversal.
 Then we loop over s, from beginning to end and check the occurence of the character, whose number of occurrences in s, stored in map in 1.

Time Complexity: O(n)
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.size();
        map<char, int> mp;
        for(auto c:s)
        {
            mp[c]++;
        }
        for(int i=0; i<len; i++)
        {
            if(mp[s[i]]==1)
                return i;
        }
        return -1;
    }
};
