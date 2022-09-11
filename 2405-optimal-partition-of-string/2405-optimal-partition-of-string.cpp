class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        set <char> st;
        int ans = 1;
        for(auto it : s)
        {
            if(st.find(it) == st.end())
            {
                st.insert(it);
            }
            
            else{
                ans++;
                st.clear();
                st.insert(it);
            }
        }
        return ans;
    }
};