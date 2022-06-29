// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    bool knows(vector<vector<int> >& M, int n, int a, int b)
    {
        if(M[a][b] == 1)
        {
            return true;
        }
        return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
       for(int i = 0; i < n; i++)
       {
           s.push(i);
       }
        
        while(s.size() > 1)
        {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            
            if(knows(M, n, a ,b))
                s.push(b);
            else
                s.push(a);
        }
        
        //now, there is a single element left in the stack, which is the 
        //potential element to become the clebrity
        
        int celeb = s.top();
        int rcount = 0, ccount = 0;
        bool rowcheck, colcheck;
        
        for(int i = 0; i < n; i++)
        {
            if(M[celeb][i] == 0) rcount++; // this is to check the celebrity row 
           
            if(M[i][celeb] == 1) ccount++;//this is to check for the celebrity column
        }
        
        if(rcount == n && ccount == (n - 1)) return celeb;
        
        return -1;

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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends