/*
The Concept of this Approach is:
    We need to traverse from 1 to n, and find the first element in this range whose API call returns Bad version as output.
    Time Complexity: O(n)
But in this particular question, we need to find a approach which is better than O(n) due to constraints of Time
We can do this by Binary Search: We need to search for the first bad version using Binary search and this will final result
  Time Complexity: O(log n)

*/

class Solution {
public:
    int firstBadVersion(int n) {
        int lower_bound = 1;
        int upper_bound = n;
        int result = 0;
        while(lower_bound<=upper_bound)
        {
            int mid = lower_bound + (upper_bound-lower_bound)/2;
            if(mid != 1 && (isBadVersion(mid) && !isBadVersion(mid-1)))
            /*If this mid version is a bad version but the version before this was a good version, then our                 answer will be this mid version*/
            {
                result = mid;
                break;
            }
            else if(mid == 1 && isBadVersion(mid))
            {
            /*If this mid version is the starting version of the range and it is a Bad Version*/
              result= mid;
              break;
            }
            else if(!isBadVersion(mid))
               lower_bound = mid+1;
            else if(isBadVersion(mid))
               upper_bound = mid-1;
        }
        return result;
    }
};
