/*
There are two approach  to this problem:---

O(n^2) time Complexity or Brute Force approach:
    In this approach we need to calculate how many jewels in J of each type are present in S, we need to calculate total of this and that will be our answer.

O(n) time complexity using map stl:
    We will keep count of each stone of S in the map and we will use the map to find how many jewels of each type are present and add them up, and that will be our result.
    
*/

//First Approach
//O(n^2) approach
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int result = 0;
        for(int i=0; i<J.size(); i++)
        {
            for(int j=0; j<S.size(); j++)
            {
                if(J[i]==S[j])
                    result++;
            }
        }
        return result;
      }   
    };

//Second Approach
//O(n) approach
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int result = 0;
        map<char, int> mp;
        for(int i=0; i<S.size(); i++)
            mp[S[i]]++;
        for(int i=0; i<J.size(); i++)
            result += mp[J[i]];
        return result;
    }
};
