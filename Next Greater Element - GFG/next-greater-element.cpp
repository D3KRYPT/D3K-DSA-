// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    typedef long long ll;
    //Function to find the next greater element for each element of the array.
    vector<ll> nextLargerElement(vector<long long> arr, int n){
       stack<ll> s;
       s.push(arr[n-1]);
       vector<ll> ans(n);
       ans[n-1] = -1;
       
       for(ll i = n - 2; i >= 0; i--)
       {
           while(!s.empty() && s.top() < arr[i])
           {
               s.pop();
           }
           ll ele = s.empty() ? -1 : s.top();
           ans[i] = ele;
           
           s.push(arr[i]);
       }
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends