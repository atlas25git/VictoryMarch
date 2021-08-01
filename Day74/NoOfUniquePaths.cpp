class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        int dp[a][b]={0};
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                if(!i)
                    dp[i][j]=1;
                else if(!j)
                    dp[i][j]=1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[a-1][b-1];
    }
};


class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //basically the idea here is that for any given i,j cell
        //we could have reached there from eihter of the 2 options
        //i-1,j or i,j-1
        //we start from base case and thus fill in the remaining array
        
        int dp[a][b]={0};
        for(int i=0;i<a;i++)dp[i][0]=1;
        for(int i=0;i<b;i++)dp[0][i]=1;
        
        for(int i=1;i<a;i++)
            for(int j=1;j<b;j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[a-1][b-1];
        
    }
};