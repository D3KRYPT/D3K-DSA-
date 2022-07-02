// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& dfsvisited, int parent)
    {
        visited[node] = 1;
        dfsvisited[node] = 1;
        
        for(auto &it : graph[node])
        {
            if(!visited[it])
            {
                if(dfsCheck(it, graph, visited, dfsvisited, node))
                {
                    return true;
                }
            }
            
            else if(dfsvisited[it])
                return true;
        }
        
        dfsvisited[node] = 0;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	   int n = N;
	    vector<int> visited(n, 0);
	    vector<int> dfsvisited(n, 0);
        
        vector<vector<int>> graph(n);
        
	    for(auto &it : prerequisites)
	    {
	        graph[it.first].push_back(it.second);
	    }
	    
	    for(int i = 0; i < n; i++)
	    {
	        if(!visited[i])
	        {
	            if(dfsCheck(i, graph, visited, dfsvisited, -1))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends