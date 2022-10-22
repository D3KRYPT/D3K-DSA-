class Solution {
private:
    int findingAtmost(vector <int>& nums, int target)
    {
        int n = nums.size();
        int start = 0, end = 0, count = 0, sum = 0;
        
        if(target < 0) return 0;
        
        while(end < n)
        {
            sum += nums[end];
            
            while(sum > target)
            {
                sum -= nums[start];
                start++;
            }
            
            count += end - start + 1;
            end++;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return findingAtmost(nums, goal) - findingAtmost(nums, goal - 1);
    }
};