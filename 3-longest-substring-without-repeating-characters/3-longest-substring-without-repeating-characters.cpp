class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        int i = 0, j = 0;
        int cnt;
        int count[256] = {0};
        int maxi = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {
            count[s[i]]++;
            
            if(count[s[i]] >= 2)
            {
                while(count[s[i]] != 1)
                {
                    count[s[j]]--;
                    j++;
                }
            }
            else{
                cnt = i - j + 1;
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    
    }
};