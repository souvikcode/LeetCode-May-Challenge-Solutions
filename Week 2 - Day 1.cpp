/*
The basic concept of this question is:
  Mathematically, slope of consecutive points must be equal for all points along the line.So, first find the slope of first two points, 
  then check for consecutive points if their slopes are equal or not. 
 
Time Complexity: O(n)
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double slope;
        slope = double(coordinates[0][1]-coordinates[1][1])/double(coordinates[0][0]-coordinates[1][0]);
        if(coordinates.size()==2)
            return true;
        else
        {
            for(int i=1; i<coordinates.size()-1; i++)
            {
                if(double(coordinates[i][1]-coordinates[i+1][1])/double(coordinates[i][0]-coordinates[i+1][0]) != slope)
                    return false;
            }
            return true;
        }
    }
};
