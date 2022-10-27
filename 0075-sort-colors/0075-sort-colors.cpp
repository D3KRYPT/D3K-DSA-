class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
                zeros++;
            else if(nums[i] == 1)
                ones++;
            else
                twos++;
        }
        cout << zeros <<" "<<ones<<" "<<twos;
        for(int i = 0; i < zeros; i++)
        {
            nums[i] = 0;
        }
        
        for(int i = zeros; i < n - twos; i++)
        {
            nums[i] = 1;
        }
        
        for(int i = zeros + ones; i < n; i++)
        {
            nums[i] = 2;
        }
    }
};