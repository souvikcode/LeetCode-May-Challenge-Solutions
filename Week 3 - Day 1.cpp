/*
Usage of Kadane algorithm twice in no wrapped up array and in wrapped up array.
Time Complexity: O(n)
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int no_wrap = 0;
        int max_ending_here = 0;
        int pos = 0;
        for(int i=0; i<A.size(); i++)
        {
            max_ending_here += A[i];
            if( max_ending_here < 0)
                  max_ending_here = 0;
            if( max_ending_here > no_wrap)
                no_wrap =  max_ending_here;
        }
       int flag = 1;
       for(int i=0; i<A.size(); i++)
       {
         if(A[i] >= 0)
           flag = 0;
       }
       if(flag)
          no_wrap = *max_element(A.begin(), A.end());        
       int sum = 0;
       for(int i=0; i<A.size(); i++)
       {
        sum += A[i];
        }
        for(int i=0; i<A.size(); i++)
              A[i] = -A[i];
        int wrap = 0;
        max_ending_here = 0;
        //int pos = 0;
        for(int i=0; i<A.size(); i++)
        {
            max_ending_here += A[i];
            if( max_ending_here < 0)
                  max_ending_here = 0;
            if( max_ending_here > wrap)
                wrap =  max_ending_here;
        }
        sum += wrap;
        if(sum > no_wrap && sum!=0)
          return sum;
        else 
          return no_wrap;
    }
};
