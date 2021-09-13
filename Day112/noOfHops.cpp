class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // int m = 1e9+7;
        // vector<int>dp(n+1,0);
        // dp[1]=1;
        // dp[2]=2;
        // dp[3]=4;
        // for(int i=4;i<=n;i++)
        //     dp[i]=(dp[i]%m + dp[i-1]%m)%m,
        //     dp[i]=(dp[i]%m + dp[i-2]%m)%m,
        //     dp[i]=(dp[i]%m + dp[i-3]%m)%m;
        
        // return dp[n];
        
        int m = 1e9+7;
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<4;j++)
                if(j<=i)
                    dp[i] = (dp[i]%m + dp[i-j]%m)%m;
        
        return dp[n];
    }
};