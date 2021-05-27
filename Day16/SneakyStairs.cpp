// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int fib(int n)
    {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
     
    // Returns number of ways to
    // reach s'th stair
    int countWaysRec(int s)
    {
        return fib(s + 1);
    }
    
    int countWaysUtil(int n, int m1)
{
    // int res[n];
    // res[0] = 1;
    // res[1] = 1;
    //  int mod = (int)(1e9+7);
     
    // for(int i = 2; i < n; i++)
    // {
    //   res[i] = 0;
        
    //   for(int j = 1; j <= m && j <= i; j++)
    //       res[i] = (res[i]%mod + res[i-j]%mod)%mod;
    // }
    // return res[n - 1];
    
     long long m = (int)(1e9+7);
        long long dp[n+1];memset(dp,0,sizeof(dp));
        
        dp[0]=1;dp[1]=1;dp[2]=2;dp[3]=3;
        
        for(int i=4;i<n+1;i++)dp[i] = (dp[i-1]%m + dp[i-2]%m)%m;
        
        return dp[n];
    
}
     
    // Returns number of ways to reach s'th stair
    int countWays(int s)
    {
        return countWaysUtil(s , 2);
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends