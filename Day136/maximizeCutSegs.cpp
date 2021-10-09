class Solution
{
    public:
    
    vector<int>dp;
    
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {   
        dp.resize(n+1,-1);
        // mcRec(n,vector<int>({x,y,z}));
        vector<int>cuts({x,y,z});
        //bottom up
        dp[0] = 0;
        for(auto x: cuts)
        for(int i=1;i<=n;i++)
        {
            if(x<=i && dp[i-x]!=-1)
                dp[i] = max(dp[i],dp[i-x]+1);

        }
        
        return dp[n]==-1?0:dp[n];
    }
    
    int mcRec(int n, vector<int> cuts)
    {
        if(n<0)return -1;
        if(n==0)return 0;
        if(dp[n])return dp[n];
        int res = INT_MIN;
        for(auto x: cuts)
            res = max(res,mcRec(n-x,cuts));
        if(res==-1)return dp[n] = res;
        else return dp[n] = res+1;
    }
};