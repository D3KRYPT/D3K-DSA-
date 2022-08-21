class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0, r = n - 1, mid;
        
        while(l <= r)
        {
            mid = (l + r) / 2;
            
            bool checkHalf = (mid - l) % 2 == 0;
            
            if(mid + 1 < n && nums[mid] == nums[mid + 1])
            {
                if(checkHalf)
                    l = mid + 2;
                else r = mid - 1;
            }
            
           else if(mid && nums[mid] == nums[mid - 1])
            {
                if(checkHalf)
                    r = mid - 2;
                else l = mid + 1;
            }
            
            else return nums[mid];
        }
        return -1;
        
    }
};