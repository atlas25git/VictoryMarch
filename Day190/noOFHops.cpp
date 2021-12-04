#define ll long long
class Solution
{
    ll m = 1e9+7;
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {   
        return cwDP(n);
        if(n<3)return n;
        int a = 1,b=2,c=4;
        
        n-=3;
        while(n-->0)
        {
            ll s = ((a%m + b%m)%m + c%m)%m;
            a = b;
            b = c;
            c = s;
        }
        return c;
    }
    
    ll cwDP(int n)
    {
        vector<int> steps({1,2,3});
        vector<int> dp(n+1,0);
        dp[0]=1,dp[1]=1,dp[2]=2,dp[3]=4;
        
        for(int i=4;i<=n;i++)
        for(auto x: steps)
            // if(x<=i)
            dp[i] = (dp[i]%m + dp[i-x]%m)%m;
            
        return dp[n];
    }
};
