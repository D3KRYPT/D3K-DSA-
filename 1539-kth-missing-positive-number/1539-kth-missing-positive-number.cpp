class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        int high = arr[n-1] + k;
        int cnt = 0;
        int ans = -1;
        for(int i = 1; i <= high; i++)
        {
            if(find(arr.begin(), arr.end(), i) == arr.end())
            {
                cnt++;
                
                if(cnt == k)
                {
                    //return i;
                    ans = i;
                    break;
                }
            }
        }
        
        if(ans == -1)
            return arr[n-1] + k;
        else
            return ans;
    }
};