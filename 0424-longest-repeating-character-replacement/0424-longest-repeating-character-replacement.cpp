class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0;
        int n = s.length();
        unordered_map <char, int> um;
        int maxi = INT_MIN;
        int ans = INT_MIN;
        while(j < n)
        {
            um[s[j]]++;
            maxi = max(maxi, um[s[j]]);
            
            if(j - i + 1 - maxi > k)
            {
                um[s[i]]--;
                i++;
            }
            
            ans = max(ans, j - i + 1);
            j++;
            
        }
        return ans;
    }
};