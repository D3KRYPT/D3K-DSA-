class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> res;
        for(int i = 0; i < n; i++)
        {
            vector < int > temp;
            for(int j = 0; j < n; j++)
            {
              temp.push_back(matrix[j][i]);  
            }
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
        }
        
        matrix = res;
    }
};