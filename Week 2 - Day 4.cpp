/*
Use Breadth First Search to traverse from the starting position to its neighbouring position, if the value at that index is same as starting index, then change its value to newColor and add it to the queue used for Breadth First Search else leave that cell and continue to the cells in other direction
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int> > q;
        //sr -= 1;
        //sc -= 1;
        int row_size = image.size();
        int column_size = image[0].size();
        int r = sr;
        int c = sc;
        /*We will create another variable 'n' which contains a value out of range of newColor
         and image[i][j] in order to avoid conflicts with values of image[i][j] and newColor
        */
        int n = -1;
        bool vis[row_size][column_size];
        memset(vis, false, sizeof(vis));
        int src = image[sr][sc];
        vis[sr][sc] = true;
        q.push(make_pair(sr,sc));
        image[sr][sc] = n;
        while(!q.empty())
        {
            int sr1 = q.front().first;
            int sc1 = q.front().second;
            
            //int flag = 1;
            while(sr1-1 >=0 && image[sr1-1][sc1]==src)
            {
                if(!vis[sr1-1][sc1])
                {
                    vis[sr1-1][sc1] = true;
                    q.push(make_pair(sr1-1, sc1));
                    image[sr1-1][sc1]=n;
                    sr1--;
                }
            }
            sr1 = q.front().first;
            sc1 = q.front().second;
            while(sc1-1 >=0 && image[sr1][sc1-1]==src)
            {
                if(!vis[sr1][sc1-1])
                {
                    vis[sr1][sc1-1] = true;
                    q.push(make_pair(sr1, sc1-1));
                    image[sr1][sc1-1]=n;
                    sc1--;
                }
            }
            sr1 = q.front().first;
            sc1 = q.front().second;
            while(sr1+1 < row_size && image[sr1+1][sc1]==src)
            {
                if(!vis[sr1+1][sc1])
                {
                    vis[sr1+1][sc1] = true;
                    q.push(make_pair(sr1+1, sc1));
                    image[sr1+1][sc1]=n;
                    sr1++;
                }
            }
            sr1 = q.front().first;
            sc1 = q.front().second;
            while(sc1+1 < column_size && image[sr1][sc1+1]==src)
            {
                if(!vis[sr1][sc1+1])
                {
                    vis[sr1][sc1+1] = true;
                    q.push(make_pair(sr1, sc1+1));
                    image[sr1][sc1+1]=n;
                    sc1++;
                }
            }
            q.pop();
        }
        for(int i=0; i<row_size; i++)
            for(int j=0; j<column_size; j++)
                 if(image[i][j] == -1)
                     image[i][j] = newColor;
        return image;
    }
};
