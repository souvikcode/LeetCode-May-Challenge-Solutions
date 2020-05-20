/*
The basic concept used in this code is same as finding the existence of anagram of a string in another string.
Time complexity-O(n)
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string s = s2;
        string p = s1;
        if(s1.size() == 0)
          return true;
        vector<int> pos;
        if(s.size() < p.size())
            return false;
        if(s == p)
        {
            pos.push_back(0);
            return true;
        }
        int n = p.size();
        map<char, int> mp1;
        map<char, int> mp2;
        for(int i=0; i<p.size(); i++)
            mp1[p[i]]++;
        int j = -1;
        for(int i=0; i<s.size(); i++)
        {
            mp2[s[i]]++;
            if(i>=n-1)
            {
               if(mp2==mp1)
                pos.push_back(i-n+1);
               j++;
               mp2[s[j]]--;
               if(mp2[s[j]]==0)
                   mp2.erase(s[j]);
            }
        }
        if(pos.size())
          return true;
        else
          return false;
    }
};
