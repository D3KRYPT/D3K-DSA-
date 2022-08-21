class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        int start = 1, low = n-2;
        
        while(start <= low)
        {
            int mid = ( start + low ) / 2;
            
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid + 1])
                return mid;
            
            else if (arr[mid]  > arr[mid-1] && arr[mid] < arr[mid+1])
            {
                start = mid + 1;
            }
            
            else //(arr[mid] < arr[mid-1] && arr[mid] < arr[mid+1])
            {
                low = mid - 1;
            }
        }
        return -1;
    }
};