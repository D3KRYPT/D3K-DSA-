class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> s(bank.begin(), bank.end());
        
        if(s.find(end) == s.end())
        {
            return -1;
        }
        
        queue<string> q;
        q.push(start);
        
        int ans = 0;
        char arr[4] = {'A', 'C', 'G', 'T'};
        while(!q.empty())
        {
            int n = q.size();
            ans++;
            while(n--)
            {
                string curr = q.front();
                q.pop();
                if(curr == end)
                    return ans;
                
                for(int i = 0; i < curr.length(); i++)
                {
                    string temp = curr;
                    for(int j = 0; j < 4; j++)
                    {
                        temp[i] = arr[j];
                        
                        
                        /*if(temp.compare(curr) == 0)
                            continue;*/
                        if(temp.compare(end) == 0)
                            return ans ;
                        if(s.find(temp) != s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return -1;
    }
};