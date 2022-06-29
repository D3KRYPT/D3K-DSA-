class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26);
        int n = s.size();
        
        for(int i = 0; i < n; i++)
        {
            last[s[i] - 'a'] = i;
        }
        
        vector<bool> seen(26, false);
        stack <char> st;
        
        for(int i = 0; i < n; i++)
        {
            if(seen[s[i] - 'a'])
                continue;
            //if the element is not taken, only then we take it, otherwise we skip the element.
            while(st.size() > 0 && st.top() > s[i] && last[st.top() - 'a'] > i)
            {
                seen[st.top() - 'a'] = false;
                st.pop(); 
            }
            
            st.push(s[i]);
            seen[s[i] - 'a'] = true;
        }
        
        string ans = "";
        while(!st.empty())
        {
            ans = ans + st.top();
            st.pop();
        }
        reverse(ans.begin(),  ans.end());
        
        return ans;
    }
};