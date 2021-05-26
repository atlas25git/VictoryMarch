// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    int countWaysR(int n){
        vector<int> dp(n+1,0);
        dp[0]=1;//base case
        
        //we're creating the table where index i denotes value of given no,
        //and we fill it in the fashion of bottom up manner as in no of, iterations
        //starting from 1 to upto N 
        int mod = (int)(1e9+7);
    
        for(int j=1;j<n+1;j++)
                dp[j]=(dp[j]%mod+dp[j-1]%mod)%mod;
                
        for(int j=2;j<n+1;j++)
                dp[j]=(dp[j]%mod+dp[j-2]%mod)%mod;
        
        return dp[n]%mod;
        
    }
    
    public:
    long long mod =1000000007;
    
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        long long res[m + 1];
        
        //base cases
        res[0] = 1;
        res[1] = 1;
        
        //storing number of ways to reach the ith index as 
        //number of ways to reach (i-2)th index +1.
        for (int i = 2; i <= m; i++)  
            res[i] = (res[i-2] + 1);
        
        //returning the result.
        return res[m];

    }
    int countWays(int m){int res = 1+m/2;return res;}
};


// { Driver Code Starts.
int main()
{
    //taking count of testcases
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
}  // } Driver Code Ends