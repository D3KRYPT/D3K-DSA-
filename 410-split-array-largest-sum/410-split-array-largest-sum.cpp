class Solution {
    private:
    bool isPossible(int mid, vector <int> &arr, int m, int n)
    {
        int cnt = 1;
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > mid) return false;
            
            if(sum + arr[i] > mid)
            {
                cnt++;
                sum = arr[i];
            }
            else{
                sum += arr[i];
            }
        }
        if(cnt > m) return false;
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int mini = INT_MAX, sum = 0;
        
        for(auto it : nums)
        {
            mini = min(mini, it);
            sum  = sum + it;
        }
        
        int low = mini;
        int high = sum;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(isPossible(mid, nums, m, n))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
         
    }
};