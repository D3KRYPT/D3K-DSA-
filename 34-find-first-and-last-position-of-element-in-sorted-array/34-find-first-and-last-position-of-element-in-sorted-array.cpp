class Solution {
public:
    int find(vector<int> &nums, int target)
    {
         
        int n = nums.size();
        int start = 0, end = n - 1;
        int res = n;
        //int mid = (start + end) / 2;
        
        while(start <= end)
        {
            int mid = (start + end) / 2;
            
            if(nums[mid] >= target) //then this mid is a possible candidate for becoming a ans
            {
                res = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = find(nums, target);
        int b = find(nums, target + 1) - 1;
        
        if(a <= b)
            return {a,b};
        return {-1, -1};
     }
};