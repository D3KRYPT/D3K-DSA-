class Solution {
public:
   bool isPossible(vector<int> &piles, int h, long long mid)
    {
        long long hrs = 0;
        
        for(int pile : piles)
        {
            int div = pile / mid;
            hrs = hrs + div;
            
            if(pile % mid != 0)
                hrs++;
        }
        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        long long maxi = INT_MIN;
        
        for(auto pile : piles)
        {
            if(pile >  maxi)
                maxi = pile;
        }
        
        long long low = 1, high = 1000000000;
        
        while(low <= high)
        {
            long long mid = (low + high) / 2;
            
            if(isPossible(piles, h, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
       return low;
    }
};