class Solution
{
    public:
    //Function to find the nth fibonacci number using top-down approach.
    long long findNthFibonacci(int number, long long int dp[])
    {
        if(dp[number]>0)return dp[number];
        
        dp[number]=findNthFibonacci(number-1,dp) + findNthFibonacci(number-2,dp);
        return dp[number];
    }

};