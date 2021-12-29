class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {   //don't forget cpp_int
        cpp_int dp[n+1];
        dp[0]=1;
        for(int i=1;i<=n;i++)
            dp[i] = (2*(2*i-1))*dp[i-1]/(i+1);
        return dp[n];
        
    }
};
