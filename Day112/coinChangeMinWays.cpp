class Solution
{
    public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
    long long numberOfWays(int c[],int n,int val)
    {
        vector<int>dp(val+1,0);
        
        dp[0]=1;
        // /here instead of taking the min value we're adding up the stuff
        //of possible solutions
        //here it is considering the ordered pairs too
        // for(int v=1;v<=val;v++)
        //     {
        //         for(int i=0;i<n;i++)
        //         {
        //             int coin = c[i];
        //             if(coin<=v)
        //                 dp[v]+=dp[v-coin];
        //         }
        //     }
        
        
        //making sets whr order doesn't matter
        for(int i=0;i<n;i++)
        {
            int coin = c[i];
            for(int v=1;v<=val;v++)
                if(v>=coin)
                    dp[v]+=dp[v-coin];
        }
            
        return dp[val];
    }
};