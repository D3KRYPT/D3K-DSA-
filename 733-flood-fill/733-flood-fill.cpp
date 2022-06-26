class Solution {
public:
    
    //-1 -> unvisited node, -2 -> visited node 0 -> nothing to do node
    
    bool isValid(int i, int j, int rs, int cs, vector<vector<int>>& visited, vector<vector<int>>& image, int initialCol)
    {
        if(i < rs && i >= 0 && j <cs && j >= 0 && visited[i][j] == -1 && image[i][j] == initialCol)return true;
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> q;
        
        int rs = image.size();
        int cs = image[0].size();
        vector<vector<int>> visited(rs, vector<int> (cs, -1));
        
        q.push({sr, sc});
        visited[sr][sc] = -2;
        int initialCol = image[sr][sc];
        image[sr][sc] = newColor;
        
        int stepsx[4] = {-1, 0, 1, 0};
        int stepsy[4] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();
            
            for(int i = 0 ; i < 4; i++)
            {
                int nexti = x + stepsx[i];
                int nextj = y + stepsy[i];
                
                if(isValid(nexti, nextj, rs, cs, visited, image, initialCol))
                {
                    visited[nexti][nextj] = -2;
                    image[nexti][nextj] = newColor;
                    q.push({nexti, nextj});
                }
            }
        }
        return image;
    }
};