class Solution {
    typedef pair<int,int> pp;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pp , vector<pp>, greater<pp>> minH;
        vector<int> ans;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
           minH.push({it->second, it->first});
            
            if(minH.size() > k) minH.pop();
            
        }
        
        while(!minH.empty())
        {
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }
};