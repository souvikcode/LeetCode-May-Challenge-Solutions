/*
The main concept behind this question is to check if total number of characters of a particular type, lets say x, which occur in ransomNote, must be greater than or equal to total number of times x occurs in magazine
So, we use two maps to keep count of number of occurences of characters in both strings
Time Complexity: O(n)
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int>mp;
        map<char, int>mp1;
        for(int i=0; i<ransomNote.size(); i++)
             mp[ransomNote[i]]++;
        for(int i=0; i<magazine.size(); i++)
             mp1[magazine[i]]++;
        for(auto m:mp)
        {
            if(mp1[m.first]<m.second)
                return false;
        }
        return true;
    }
};
