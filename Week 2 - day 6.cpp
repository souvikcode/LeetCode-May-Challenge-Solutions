/*
we need to use Stack Data structure to store numbers such that we have to push elemnts from num into stack and check from top to bottom of stack, the elements which are greater than current element of num and continue to do it until k != 0.
We will create the result string from this stack and remove zeroes from the beginning of this string.
Time Complexity : O(n^2)
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> s;
        for(char c: num)
        {
            while(k && !s.empty() && s.top() > c)
            {
                s.pop();
                k--;
            }
            s.push(c);
        }
        if(k!=0)
        {
         while(k--)
         {
             s.pop();
         }
        }   
        while(s.size())
        {
            char m = s.top();
            ans = m + ans;
            s.pop();
        }
        int pos = 0;
        while(pos != ans.size() && ans[pos]=='0')
        {
            pos++;
        }
        pos -= 1;
        if(ans.size()==0)
            return "0";
        if(pos==ans.size()-1)
            return "0";
        else
        {
            string final_ans = "";
            for(int i=pos+1; i<ans.size();i++)
                final_ans += ans[i];
            return final_ans;
        }
    }
};
