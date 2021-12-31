class Solution
{
    public:
    int mod = 1e9+7;
    unordered_map<int,int> memo;
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {   int m = 1e9+7;
        return recWays(n);
        // basically the version of coin change where order does matter
        int a = 1,b=1;
        n--;
        
        while(n--)
        {
            int s = (a%m+b%m)%m;
            a=b;
            b=s;
        }
        
    return b;    
    }
    
    int recWays(int m)
    {
        if(memo.count(m))return memo[m];
        if(!m) return 1;
        int cnt = 0;
        for(int i=1;i<=2;i++)
        {
            if(i<=m)
                cnt = (cnt%mod + recWays(m-i)%mod)%mod;
        }
        
        return memo[m] = cnt;
    }
};
