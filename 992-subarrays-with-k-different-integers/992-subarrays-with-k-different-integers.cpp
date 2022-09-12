class Solution {
public:
    int find (vector<int>& nums, int k)
    {
        int j = 0;
        int n = nums.size();
        int dstchr = 0, count = 0;
        vector <int> mp(20002);
        
       for(int i = 0; i < n; i++)
       {
           if(mp[nums[i]] == 0)
            {
               dstchr++;
                mp[nums[i]]++;
            }
           else
           {
                mp[nums[i]]++;
           }
           
           if(dstchr <= k)
           {
               count += i - j + 1;
           }
           else{
               while(j < n && j <= i && dstchr > k)
               {
                    mp[nums[j]]--;
                    if(mp[nums[j]]==0)
                        dstchr--;
                    j++;
               }
               count+=(i-j+1);
           }
               
       }
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (find (nums, k) - find ( nums,  k - 1)) ;
    }
};