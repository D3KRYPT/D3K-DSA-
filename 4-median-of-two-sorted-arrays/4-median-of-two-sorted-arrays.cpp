class Solution {
public:
   
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
                vector <int> finalvec(nums1.size() + nums2.size());
        
        int i = 0, j = 0, k = 0;
        
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] < nums2[j])
                finalvec[k++] = nums1[i++];
            
            else
            {
                finalvec[k++] = nums2[j++];
            }
        }
        
        if(i < nums1.size())
            
        {
            while(i < nums1.size())
            {
                finalvec[k++] = nums1[i++];
            }
            
        }
        
        else if(j < nums2.size())
        {
            while(j < nums2.size())
            {
                finalvec[k++] = nums2[j++];
            }
        }
        
        int n = nums1.size();
        int m = nums2.size();
        
        n = n+m;
        if(n%2==1) 
            return finalvec[((n+1)/2)-1];
        else return ((float)finalvec[(n/2)-1]+(float)finalvec[(n/2)])/2;
    }
};