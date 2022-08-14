class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int target = arr.size() / 2;
        
        unordered_map <int, int> um;
        
        for(auto &it : arr)
            um[it]++;
        
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < um.size(); i++)
        {
            if(um[i] != 0)
            {
                pq.push({um[i], i});
            }
        }
        int count = 0;
        int targetToReach = 0;
        
        while(!pq.empty())
        {
            //int topEle = pq.top();
            targetToReach = targetToReach + pq.top().first;
            count++;
            
            if(targetToReach >= target)
                break;
            pq.pop();
        }
     return count;   
    }
};