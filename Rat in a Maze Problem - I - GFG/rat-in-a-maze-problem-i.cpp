// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i, int j, vector<vector<int>> &a, vector<string> &ans, vector<vector<int>> &vis, string s, int n)
    {
        if(i == n - 1 && j == n - 1)
        {
            ans.push_back(s);
            return;
        }
        
        //DLRU
        
        //downward
        if(i + 1 < n && vis[i + 1][j] == 0 && a[i + 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i + 1, j, a, ans, vis, s + 'D', n);
            vis[i][j] = 0;
        }
        
        //leftmove
          if(j - 1 >= 0  && vis[i][j - 1] == 0 && a[i][j - 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j-1, a, ans, vis, s + 'L', n);
            vis[i][j] = 0;
        }
        
        
        //right move
          if(j + 1 < n && vis[i][j + 1] == 0 && a[i][j + 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j + 1, a, ans, vis, s + 'R', n);
            vis[i][j] = 0;
        }
        
        
        //upward move
          if(i - 1 >= 0 && vis[i-1][j] == 0 && a[i - 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i - 1, j, a, ans, vis, s + 'U', n);
            vis[i][j] = 0;
        }
        
    }
    
   public: 
    vector<string> findPath(vector<vector<int>> &m, int n) {
        /*steps:
        first i have to create a visited matrix of tghe same size as the given 
        then I have to traverse the original matrix in a lexicographic way DLRU
        if possible. Once i have reached the cell (n-1,n-1) i will traverse back
        i.e backtrack, and have to check for the rest of the lexicographic order*/
        
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0));
        
        if(m[0][0] == 1)
        {
            solve(0,0,m,ans, vis, "", n);
        }
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends