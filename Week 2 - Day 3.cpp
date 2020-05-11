/*
Problem link: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/

Concept required: 
 For each people who are trusting other people, we will create a map for each person which will map to a set 
  which contains a list of people they trust.
 Now we need to search for the person in range 1 to N, who does not trust any other person, that is its set   is empty, and if there exist no person or more than one person whose set is empty then return -1, else       that person whose set is empty will be your answer. 

Time Complexity: O(nlogn)
*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        map<int, set<int> >mp;
        for(int i=0; i<trust.size(); i++)
        {
            mp[trust[i][0]].insert(trust[i][1]);
        }
        int result = 0;
        for(int i=1; i<=N; i++)
        {
            if(mp[i].size()==0)
            {
                if(!result)
                    result = i;
                else
                    return -1;
            }
        }
        if(!result)
            return -1;
        for(auto m:mp)
        {
            if(m.second.find(result)==m.second.end() && m.first!=result)
                return -1;
        }
        return result;
    }
};
