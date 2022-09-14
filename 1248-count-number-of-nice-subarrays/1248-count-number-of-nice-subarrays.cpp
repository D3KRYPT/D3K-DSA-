class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size());
        
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] % 2 == 1){
                prefixSum[i] = 1;
            }
        }
        
        for(int i = 1; i < nums.size(); i++){
            prefixSum[i] += prefixSum[i - 1];
        }
        
        unordered_map<int,int> map;
        
        map[0] = 1;
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if (prefixSum[i] - k >= 0){
                ans += map[prefixSum[i] - k];
            }
            map[prefixSum[i]]++;
        }
        return ans;
    }
};
