/*
Problem Link : https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/

The main concept of the question is:
  To convert the given "num" to its Binary Equivalent,then flipping the bits of this binary equivalent and converting this resultant Binary Equivalent to its decimal representation. 
  Time Complexity: O(n)
*/
class Solution {
public:
    int findComplement(int num) {
        string bin_num = "";
        //loop  to convert decimal to binary
        while(num)
        {
            int p = num%2;
            if(p==1)
              bin_num = '1'+bin_num;
            else
              bin_num  = '0'+bin_num ;
            num /= 2;
        }
        int result = 0;
        int c = 0;
        for(int i=bin_num .size()-1; i>=0; i--)
        {
            int b;
            if(bin_num[i]=='1')
                b = 0;
            else
                b = 1;
            result += b*(1<<c);
            c++;
        }
        return result;
    }
};
