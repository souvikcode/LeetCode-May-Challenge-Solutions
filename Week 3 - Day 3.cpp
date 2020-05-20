/*
We need to traverse the string s from beginning to end and check if the substring of s from ith to ith+length(p) is an anagram of p. 
Time Complexity: O(n)
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pos;
        if(s.size() < p.size())
            return pos;
        if(s == p)
        {
            pos.push_back(0);
            return pos;
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
        return pos;
    }
};
