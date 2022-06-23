class Solution {
public:
    bool checkForCycle(int parent, int node, vector<vector<int>>& graph, vector<int>& visited, vector<int> &currentDFS_Visited)
    {
        visited[node] = 1;
        currentDFS_Visited[node] = 1;
        
        for(auto &it : graph[node])
        {
            if(visited[it] == 0)
            {
                if(checkForCycle(node, it, graph, visited, currentDFS_Visited))
                    return  true;
            }
            else if(currentDFS_Visited[it] == 1)
                return  true;
        }
        currentDFS_Visited[node] = 0;
        return false;
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        for(auto &x : prerequisites)
        {
            graph[x[0]].push_back(x[1]);
        }
        
        vector<int> visited(numCourses,0);
        vector<int> currentDFS_Visited(numCourses,0);
        
        for(int i = 0; i < numCourses; i++)
        {
            int parent = -1;
            if(visited[i] == 0)
            {
                if(checkForCycle(parent, i, graph, visited, currentDFS_Visited))
                    return false;
            }
        }
        return true;
    }
};