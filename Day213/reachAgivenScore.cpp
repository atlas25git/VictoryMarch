//User function tempate for C++
vector<int> scores({3,5,10});

ll countWays(int n,int i)
{
    if(n<0)return 0;
    if(n == 0)return 1;
    if(i == 0)return 0;
    int ways = 0;
    int waysinc=0,waysexc=0; 
    waysinc = countWays(n-scores[i-1],i);
    waysexc = countWays(n,i-1);
    return waysinc + waysexc;
}


//Function to find the number of distinct combinations to reach the given score.
ll count(ll n) 
{
    // return countWays(n,3);
    
    //bottom up
    vector<vector<int>> dp(4,vector<int>(n+1,0));
    
    //base case
    for(int i=0;i<4;i++)
        dp[i][0] = 1;
    
    for(int i=0;i<4;i++)
        for(int j=1;j<=n;j++)
        {
            // inc
            if(scores[i]<=j)
                dp[i][j] += dp[i][j-scores[i]];
            i?dp[i][j] += dp[i-1][j]:0;
        }
        
    return dp[3][n];
    
}