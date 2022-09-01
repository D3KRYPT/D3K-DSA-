class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {   
            map<char, int> mp;
            
            for(int j = i; j < n; j++)
            {
                mp[s[j]]++;
                int maxi = INT_MIN, mini = INT_MAX;
                for(auto it : mp)
                {
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }
                ans += (maxi - mini);
            }
        }
        return ans;
    }
};