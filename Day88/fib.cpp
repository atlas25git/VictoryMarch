class Solution
{
    public:
    //Function to find the nth fibonacci number using bottom-up approach.
    long long findNthFibonacci(int n)
    {
        long long arr[n+1];
        arr[0]=1;
        arr[1]=1;
        for(int i=2;i<n;i++)arr[i] = arr[i-1]+arr[i-2];
        return arr[n-1];
    }
};

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