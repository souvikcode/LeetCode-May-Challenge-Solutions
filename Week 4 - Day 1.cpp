/*
Use a map to store count of each chararter of string s, Then use Priority Queue or Max Heap to sort the map in decreasing order of count of each character. Form the result string, using the map formed from the Max Heap.

Time Complexity: O(n^2)
*/
class Solution {
public:
    string frequencySort(string s) {
      map<char, int> mp;
      priority_queue<pair<int, char> >p;
      if(s.size() == 0)
        return "";
      for(char c:s)
        mp[c]++;
      for(auto m: mp)
      {
        p.push(make_pair(m.second, m.first));
      }
      string result = "";
      while(!p.empty())
      {
        int count = p.top().first;
        int c = p.top().second;
        for(int i=1; i<=count; i++)
        {
          result += c;
        }
        p.pop();
      }
      return result;
    }
};
