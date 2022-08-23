class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(maxi < piles[i])
                maxi = piles[i];
        }
        long long low = 1, high = maxi;
        
        while(low <= high)
        {
            long long mid = (low + high) / 2;
            long long hrs = 0;
            
            for(int i = 0; i < n; i++)
            {
                hrs += ceil( 1.0 * piles[i] / mid);
            }
            
            if(hrs > h)
                low = mid + 1;
            else
                high = mid - 1;
            
        }
        return low;
        
    }
};