class Solution {
public:
    bool detectCycle(int node, vector<int>& visited, vector<int>& dfsVisited, vector<vector<int>>& graph,  vector<bool>& presentCycle)
    {
        visited[node] = 1;
        dfsVisited[node] = 1;
        
        vector<int> data = graph[node];
        
        for(auto &x : data)
        {
            if(!visited[x])
            {
               if(detectCycle(x, visited, dfsVisited, graph, presentCycle))
                   return presentCycle[node] = true;
            }
            
            else if(dfsVisited[x])
                return presentCycle[node] = true;
        }
        
        dfsVisited[node] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<int> visited(n, 0);
        vector<int> dfsVisited(n, 0);
        vector<bool> presentCycle(n, false);
        vector<int> ans;
        for(int i = 0 ; i < n; i++)
        {
            if(!visited[i])
            {
                detectCycle(i, visited, dfsVisited, graph, presentCycle);
            }
        }
        
        for(int i = 0 ; i < n; i++)
        {
            if(presentCycle[i] == false)
                ans.push_back(i);
        }
        
        return ans;
    }
};