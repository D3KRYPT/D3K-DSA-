class Solution {
public:
    
    int dfsTraversal(long long node, vector<bool>& visited, vector<vector<long long>>& graph, long long &nodes)
    {
        visited[node] = true;
        nodes++;
        for(auto &x : graph[node])
        {
            if(!visited[x])
            {
                dfsTraversal(x, visited, graph, nodes);
            }
        }
        return nodes;
    }
    
    long long countPairs(long long n, vector<vector<int>>& edges) {
        vector<vector<long long>> graph(n);
        long long ans = 0;
        long long ans1;
        if(edges.size() == 0)
        {
            ans1 = (n * (n-1)) / 2;
            return ans1;
        }
        for(auto &x : edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        vector<bool> visited(n, false);
        long long components = 0;
        
        vector<long long> nodesNum;
        
        for(long long i = 0 ; i < n; i++)
        {
            if(!visited[i])
            {
                long long nodes = 0;
                components++;
                dfsTraversal(i, visited, graph, nodes);
                nodesNum.push_back(nodes);
                //ans += 
            }    
        }
        long long size = nodesNum.size();
        for(int i = 0; i < size; i++)
        {
            ans += nodesNum[i] * (n - nodesNum[i]);
        }
       
       return (ans/2);
            
    }
        
};