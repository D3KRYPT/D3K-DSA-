class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res = 0;
        for(auto &it : nums)
        {
            res = res | it;
        }
        return res;
    }
};