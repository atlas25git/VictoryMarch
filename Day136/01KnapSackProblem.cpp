class Solution
{
    public:
    
    map<pair<int,int>,int> memo;
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    {  
        vector<vector<int>> dp(W+1,vector<int>(n+1,0));
        
        for(int i=1;i<=W;i++)
            for(int j=1;j<=n;j++)
            {
                if(i>=wt[j-1])
                    dp[i][j] = max(dp[i-wt[j-1]][j-1] + val[j-1],dp[i][j-1]);
                else 
                    dp[i][j] = dp[i][j-1];
            }
        
       return dp[W][n];//recKP(W,wt,val,n-1);
    }
    
    int recKP(int W,int wt[],int val[],int n)
    {
        if(W==0 || n==-1) return 0;
        if(memo.count({W,n}))return memo[{W,n}];
        
        if(wt[n]<=W)
        return memo[{W,n}] = max(
            recKP(W-wt[n],wt,val,n-1) + val[n],
            recKP(W,wt,val,n-1)
            );
        
        else return memo[{W,n}]  = recKP(W,wt,val,n-1);
    }
};