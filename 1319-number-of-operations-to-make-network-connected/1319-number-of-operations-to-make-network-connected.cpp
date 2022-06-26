class Solution {
public:
    void dfsTraversal(int node, vector<vector<int>>& graph, vector<int>& visited)
    {
        visited[node] = 1;
        
        for(auto &x : graph[node])
        {
            if(!visited[x])
            {
                dfsTraversal(x, graph, visited);
            }
        }
    }
    
    //0 -> unvisited node....1 -> visited node
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        if(connections.size() < n - 1)
            return -1;
        for(int i = 0; i < connections.size(); i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<int> visited(n, 0);
        int count = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(!visited[i])
            {
                count++;
                dfsTraversal(i, graph, visited);
            }
        }
        return count -1;
        
    }
};