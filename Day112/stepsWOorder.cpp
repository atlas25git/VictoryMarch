class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        //basically the coin change proble,
        vector<int> dp(m+1,0);
        dp[0]=1;
        for(int i=1;i<3;i++)
            {
                for(int j=1;j<=m;j++)
                    if(i<=j)
                        dp[j]+=dp[j-i];
                // for(auto x: dp)cout<<x<<" ";
                // cout<<endl;
            }
        
        return dp[m];
    }
};