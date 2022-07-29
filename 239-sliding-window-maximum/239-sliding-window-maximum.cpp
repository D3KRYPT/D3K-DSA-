class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         vector<int>res;
        int hh = 0, tt = -1;
        int q[nums.size()+10];
       
        
        for (int i = 0;i < nums.size(); i++)
        {
            if(hh <= tt && k < i - q[hh] +1) hh++;
            
            while(hh <= tt && nums[q[tt]] < nums[i]) tt--;
            q[++tt] = i;
            
            if(i >= k-1) res.push_back(nums[q[hh]]);
        }
        
        return res;
        
    }
};