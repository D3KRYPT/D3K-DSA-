class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = n / 2;
        int maxi = INT_MIN;
        unordered_map <int,int> um;
        int index;
        
        for(int i = 0; i < n; i++)
        {
            um[nums[i]]++;
            //maxi = max(maxi, um[nums[i]]);
            if(um[nums[i]] > maxi)
            {
                maxi = um[nums[i]];
                index = i;
            }
        }
        return nums[index];
    }
};