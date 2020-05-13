/*
Problem link: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/

Basic Concept of this problem: 
Use Binary Search, to find a specific pattern, the pattern is - if mid is even, then it's duplicate should be in next index, or if mid is odd, then it's duplicate  should be in previous index.check these two conditions, if any of the conditions is satisfied,then pattern is not missed, so check in next half of the array. i.e, left = mid + 1if condition is not satisfied, then the pattern is missed.So, single number must be before mid,update end to mid.

Time Complexity: O(n)
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lower = 0, upper = nums.size() - 1;
        while(lower < upper){
            int mid = lower + (upper-lower)/2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                lower = mid + 1;
            else
                upper = mid;
        }
        
        return nums[lower];
    }
};
