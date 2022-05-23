class Solution {
public:
    bool checkvalid(int l, int m, int row, int col)
    {
        if(l < 0 || m < 0 || l >= row || m >= col) return false;
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), -1));
        
        for(int i = 0 ; i < rows; i++)
        {
            for(int j = 0 ; j < cols; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        
        //here comes the bfs algorithm to solve the problem optimally
        while(!q.empty())
        {
            int l = q.front().first;
            int m = q.front().second;
            
            
            
            if(checkvalid(l+1,m,rows,cols) && ans[l+1][m] == -1)
            {
                q.push({l+1,m});
                ans[l+1][m] = ans[l][m] + 1;
                
            }
            
            if(checkvalid(l-1,m,rows,cols) && ans[l-1][m] == -1)
            {
                q.push({l-1,m});
                ans[l-1][m] = ans[l][m] + 1;
                
            }
            
            if(checkvalid(l,m+1,rows,cols) && ans[l][m+1] == -1)
            {
                q.push({l,m+1});
                ans[l][m+1] = ans[l][m] + 1;
            }
            
            if(checkvalid(l,m-1,rows,cols) && ans[l][m-1] == -1)
            {
                q.push({l,m-1});
                ans[l][m-1] = ans[l][m] + 1;
            }
            q.pop();
            
        }
        return ans;
    }
};