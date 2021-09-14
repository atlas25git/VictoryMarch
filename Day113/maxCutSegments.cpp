class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //basically it's just coin change problem with max version of coins
        vector<int> dp(n+1,INT_MIN);
        vector<int> cuts = {x,y,z};
        
        //base case
        dp[0]=0;
        
        for(int i=0;i<3;i++)
            for(int j=1;j<=n;j++)
                if(cuts[i]<=j && dp[j-cuts[i]]!=INT_MIN)
                    dp[j] = max(dp[j-cuts[i]]+1,dp[j]);
        return dp[n]==INT_MIN?0:dp[n];
    }
};