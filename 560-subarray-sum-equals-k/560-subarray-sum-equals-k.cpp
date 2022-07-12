class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int count = 0, sum = 0;
        
        unordered_map <int, int> prevsum;
        
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            
            if(sum == k) count++;
            
            if(prevsum.find(sum - k) != prevsum.end())
                count += prevsum[sum - k];
            prevsum[sum]++;
        }
        return count;
    }
};