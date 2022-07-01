class Solution {
public:
    typedef long long ll;
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<ll> degree(n, 0);
        
        for(ll i = 0; i < roads.size(); i++)
        {
            for(ll j = 0; j < 2; j++)
            {
                degree[roads[i][j]]++;
            }
        }
        
        sort(degree.begin(), degree.end());
        ll ans = 0;
        for(ll i = 0; i < n; i++)
        {
          ans += degree[i] * (i + 1);  
        }
        
        return ans;
    }
};