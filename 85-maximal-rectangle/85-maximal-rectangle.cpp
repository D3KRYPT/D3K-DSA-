class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> leftsmall(n), rightsmall(n);
        
        stack<int> s;
        for(int i = 0; i < n; i++)
        {
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            
            if(s.empty()) 
                leftsmall[i] = 0;
            else
                leftsmall[i] = s.top() + 1;
            
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        
        for(int i = n-1; i >= 0; i--)
        {
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            
            if(s.empty()) rightsmall[i] = n-1;
            
            else rightsmall[i] = s.top() -1;
            s.push(i);
        }
        int maxi = INT_MIN;
        for(int i = 0 ; i < n; i++)
        {
           maxi = max(maxi, (rightsmall[i] - leftsmall[i] + 1) * heights[i]); 
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> toBe(m, 0);
        int maxarea = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                    toBe[j]++;
                else
                    toBe[j] = 0;
            }
            int m = largestRectangleArea(toBe);
            maxarea = max(maxarea, m);
        }
        return maxarea;
    }
};