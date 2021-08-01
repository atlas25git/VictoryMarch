class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int r = s1.size(),c=s2.size();
        vector<vector<int>>dp(r+1,vector<int>(c+1));
        
        for(int i=0;i<=r;i++)dp[i][0]=0;
        for(int j=0;j<=c;j++)dp[0][j]=0;
        
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        
        return dp[r][c];
    }
};



class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        
        for(int i=0;i<=m;i++)dp[0][i]=0;
        for(int i=0;i<=n;i++)dp[i][0]=0;
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    
        return dp[n][m];
    }
};
