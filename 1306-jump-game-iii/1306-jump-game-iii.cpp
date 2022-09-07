class Solution {

    
    
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        
        vector <int> visited(n, 0);
        
        queue <int> q;
        q.push(start);
        visited[start] = 1;
        
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            
            if(arr[t] == 0)
                return true;
            
            if(t + arr[t] < n && !visited[t + arr[t]])
            {
                q.push(t + arr[t]);
                visited[t + arr[t]] = 1;
            }
            
            if( t - arr[t] >= 0  && !visited[t - arr[t]])
            {
                q.push(t - arr[t]);
                visited[t - arr[t]] = 1;
            }
            
            
        }
        return false;
    }
};