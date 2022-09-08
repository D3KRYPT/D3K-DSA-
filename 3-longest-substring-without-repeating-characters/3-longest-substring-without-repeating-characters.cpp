class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        int i = 0, j = 0;
        
        int count[256] = {0};
        int maxi = 0;
        
        while(i < n)
        {
            count[s[i]]++;
            
           
            while(count[s[i]] > 1)
            {
                count[s[j]]--;
                j++;
            }
            maxi = max(maxi, i-j+1);
            i++;
        }
        return maxi;
    }
};
                        