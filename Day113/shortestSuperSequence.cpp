class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m+1;i++)
            for(int j=0;j<n+1;j++)
            {
                if(!i)dp[i][j]=j;
                else if(!j)dp[i][j]=i;
                else 
                {
                    if(X[i-1] == Y[j-1])
                        dp[i][j] = dp[i-1][j-1]+1;
                    else
                        dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
                }
            }
        return dp[m][n];
    }
};