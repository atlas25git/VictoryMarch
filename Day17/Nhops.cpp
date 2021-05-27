// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        long long m = (int)(1e9+7);
        long long dp[n+1];memset(dp,0,sizeof(dp));
        //fibonacci when order matters and brute two loop table filling when it doesn't.
        dp[0]=1;dp[1]=1;dp[2]=2;dp[3]=4;
        
        for(int i=4;i<n+1;i++)dp[i] = ((dp[i-1]%m + dp[i-2]%m)%m + dp[i-3]%m)%m;
        
        // for(long long i=1;i<=4;i++)
        // {
        //     for(long long j=i;j<n+1;j++)
        //     {
        //         dp[j] = (dp[j]%mod + dp[j-i]%mod)%mod;
        //     }
        // }
        
        return dp[n];
        
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends