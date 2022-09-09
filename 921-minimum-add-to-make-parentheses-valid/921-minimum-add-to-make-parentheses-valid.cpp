class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <int> st;
        int cnt = 0;
        for(auto it : s)
        {
            if(it == '(')
            {
                st.push(it);
            }
            
            if(it == ')')
            {
                if(!st.empty())
                {
                    if(st.top() == '(')
                        st.pop();
                   
                }
                else
                    cnt++;
            }
                
        }
        return cnt + st.size();
    }
};