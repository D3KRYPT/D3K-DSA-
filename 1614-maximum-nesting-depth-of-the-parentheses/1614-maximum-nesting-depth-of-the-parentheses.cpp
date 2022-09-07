class Solution {
public:
    int maxDepth(string s) {
        int cnt1 = 0, cnt2 = 0;
        
        for(auto it : s)
        {
            if(it == '(')
                cnt1++;
            else if(it == ')')
                cnt1--;
            
            cnt2 = max(cnt2, cnt1);
        }
        return cnt2;
    }
};