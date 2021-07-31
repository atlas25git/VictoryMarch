// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {   int m = 1e9+7;
        // basically the version of coin change where order does matter
        vector<long> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2;j++)
            if(j<=i)
                dp[i] = (dp[i]%m + dp[i-j]%m)%m;
        }
    
    return dp[n];    
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