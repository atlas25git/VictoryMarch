// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count the number of different ways in which n can be 
    //written as a sum of two or more positive integers.
    int countWays(int n)
    {
        //infinite supply of coins, we need to compute
        //total no of possible ways
        int m = 1e9+7;
        vector<int> dp(n+1,0);
        dp[0]=1;
        
        // for(int i=1;i<=n;i++)
        //     //since we need to compute ways st n could be written as 
        //     //the sum of 2 or more numbers
        //     for(int j=1;j<=n-1;j++)
        //         if(j<=i && dp[i-j]!=0];)
        //             dp[i] += dp[i-j];
        
        for(int i=1;i<n;i++)
            for(int j=1;j<=n;j++)
                if(j>=i)
                    dp[j] = (dp[j]%m + dp[j-i]%m)%m;
                    
        return dp[n]==INT_MAX?-1:dp[n];   
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
    //taking number of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.countWays(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends