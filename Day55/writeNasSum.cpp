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
    {   int mod = 1e9+7;
        long long mod1 = 10e8+7;
        vector<int> dp(n+1,0);
        dp[0]=1;
        //<n coz n for n would not satidfy the conditon of 2 pos elements
        for(int i=1;i<n;i++)
            for(int j=1;j<=n;j++)
            {
                if(j-i>=0)
                    dp[j] = ((dp[j])%mod + dp[j-i]%mod)%mod;
            }
            
            cout<<mod<<" 1 \n";
            cout<<mod1<<" 10 \n";
        return dp[n]%mod;
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