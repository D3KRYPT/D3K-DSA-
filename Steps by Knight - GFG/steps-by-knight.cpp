// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    
    bool isValid(int first, int second, int n, vector<vector<int>>& visited)
    {
        if(first < n && first >= 0 && second < n && second >= 0 && visited[first][second] == 0)
        {
            return true;
        }
        return false;
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&k,vector<int>&t,int N)
	{
	    int srcx = k[0] - 1;
	    int srcy = k[1] - 1;
	    
	    int tx = t[0] - 1, ty = t[1] - 1;
	    int ans = 0;
	    
	    if(srcx == tx && srcy == ty)
	    {
	        return ans;
	    }
	    queue<pair<int,int>> q;
	    vector<vector<int>> visited(N, vector<int>(N, 0));
	    
	    q.push({srcx, srcy});
	    visited[srcx][srcy] = 1;
	    
	    int stepsi[8] = {1, 2, 2, 1, -2, -1, -2, -1};
	    int stepsj[8] = {2, 1, -1, -2, -1, -2, 1, 2};
	    
	   while(!q.empty())
	   {
	       int n = q.size();
	       ans++;
	       
	       while(n != 0)
	       {
	           pair<int, int> p = q.front();
	           q.pop();
	           for(int i = 0 ; i < 8; i++)
	           {
	               int nexti = p.first + stepsi[i];
	               int nextj = p.second + stepsj[i];
	               
	              if(isValid(nexti, nextj, N, visited))
	              {
	                  if(nexti == tx && nextj == ty)
	                  {
	                      return ans;
	                  }
	                  
	                  q.push({nexti, nextj});
	                  visited[nexti][nextj] = true;
	              }
	           }
	           n--;
	       }
	   }
	    
	  return ans;  
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends