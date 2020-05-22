/*
Let us create a matrix "dp" of size of number of rows of given matrix + 1 and number of columns of matrix+1.
dp[i][j] = minimum of (dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1
Each cel of dp stores number of squares submatrices of each size. If dp[i][j] = 3, means 3 sub matrices, 1 of size 1, 1 of size 2, 1 of size 3 can be formed.
Sum of all values in dp, gives us the result.
Time Complexity: O(n^2)
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
      int result = 0;
      int row = matrix.size();
      int col = matrix[0].size();
      int dp[row+1][col+1];
      memset(dp, 0, sizeof(dp));
      for(int i=1; i<row+1; i++)
      {
        for(int j=1; j<col+1; j++)
        {
          if(matrix[i-1][j-1] == 0)
            continue;
          else
          {
            vector<int> v;
            v.push_back(dp[i-1][j-1]);
            v.push_back(dp[i-1][j]);
            v.push_back(dp[i][j-1]);
            dp[i][j] = *min_element(v.begin(), v.end()) + 1;
            v.clear();
            result += dp[i][j];
          }
        }
      }
      return result;
    }
};
