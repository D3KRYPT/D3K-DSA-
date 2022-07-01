class UnionFind
{
    vector<int>  parent, size;
   public: 
    UnionFind(int n)      //constructor to initialize the parent and the size array
    {
        parent.resize(n); size.resize(n);
        
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
        
    }
    
    int findParent(int node)  //function to find the parent of two nodes
    {
        if(node == parent[node])
            return node;
       return parent[node] = findParent(parent[node]);
    }
    
    bool doUnion(int node1, int node2)  //function for union of two nodes
    {
        int n = findParent(node1);
        int m = findParent(node2);
        
        if(m == n)
            return false;
        
            if(size[n] > size[m])
            {
                size[n] += size[m];
                parent[m] = n;
            }
            else{
                size[m] += size[n];
                parent[n] = m;
            }
        
        return true;
    }
    
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        UnionFind u(n);
        
        for(auto &it : edges)
        {
            if(!u.doUnion(it[0] - 1, it[1] - 1))
                return {it[0], it[1]};
        }
        return { };
    }
};