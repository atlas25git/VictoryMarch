#define ll long long
class Solution
{   vector<int> memo;
    map<pair<int,int>,int> mp;
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {   //memo.resize(m+1,-1);
        // return dpCW(m);
        return recWaysUD(m,2);
        // return m/2+1;
    }
    
    
    ll recWaysUD(int m,int n)
    {   
        if(mp.count({m,n}))return mp[{m,n}];
        if(n == 0)return 0;
        if(!m) return 1;
        int inc = 0;
        
        if(n<=m)
            inc = recWaysUD(m-n,n);
        int exc = recWaysUD(m,n-1);
        
        return mp[{m,n}] = inc+exc;
    }
    
    //when order mattered
    ll recWays(int m)
    {
        if(!m) return 1;
        int cnt = 0;
        for(int i=1;i<=2;i++)
        {
            if(i<=m)
                cnt += recWays(m-i);
        }
        
        return cnt;
    }
    
    ll dpCW(int m)
    {
        memo.resize(m+1,0);
        memo[0] = 1;
        
        for(int i=1;i<=2;i++)
            for(int j=1;j<=m;j++)
                {
                    if(i<=j)
                        memo[j] += memo[j-i];
                }
        
        return memo.back();
    }
};