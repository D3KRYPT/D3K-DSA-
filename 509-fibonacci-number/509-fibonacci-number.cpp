class Solution {
public:
    int fib(int n) {
        //vector<int> dp(31, -1);
       static vector<int> dp(n+31, -1);
       if(n <= 1) return n;
        
        if(dp[n] != -1) 
            return dp[n];
        
        return dp[n] = fib(n-1) + fib(n-2);
    }
};