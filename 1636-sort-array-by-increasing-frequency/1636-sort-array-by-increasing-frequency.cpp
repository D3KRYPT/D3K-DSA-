class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map <int, int> map;
        
        for(auto it : nums)
            map[it]++;
        
        sort(nums.begin(), nums.end(), [&](int a, int b) 
             {return map[a] != map[b] ? map[a] < map[b] : a > b;});
        
        return nums;
        
        }
};