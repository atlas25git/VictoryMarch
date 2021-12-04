#define ll long long
class Solution
{   
    vector<int> cand;
    map<pair<int,int>,int> memo;
    public:
    //Function to count the number of different ways in which n can be 
    //written as a sum of two or more positive integers.
    int countWays(int n)
    {
        // return cWRec(n);
        // return cWDp(n);
        return cW1DDp(n);
    }
    
    int cW1DDp(int n)
    {
        vector<int> dp(n+1,0);
        
        //Here the order of loop, i.e, whether we're filling row wise
        //or column wise.
        
        dp[0] = 1;
        
        for(int i=1;i<n;i++)
            for(int j=1;j<=n;j++)
            {
                //since we're storing the results of previous state i.e,
                //with i-1 coins in the same space i.e, dp[i][j] hence we do
                //not explicitly need to add it.
                if(j>=i)
                dp[j] += dp[j-i];
            }
        return dp.back();
    }
    
    int cWDp(int n)
    {
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        //Don't confuse this with goal state, here we're just looking for
        //inferences we made from recursive solution.
        
        //Base case:
        for(int i=0;i<n;i++)dp[i][0] = 1;
        
        //The case that sum should be comprised of 2 or more entities, is ascertained
        //by our looping range of coins.
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<n;j++)
                {   
                    
                    // exclude
                    dp[j][i] += dp[j-1][i];
                    // include
                    if(j<=i)
                    dp[j][i] += dp[j][i-j];
                }
        }
        
        for(auto x: dp)
        {
            for(auto y: x)
            cout<<y<<" ";
            cout<<"\n";
        }
        
        return dp[n-1][n];
    }
    
    int cWRec(int n)
    {
        for(int i=1;i<n;i++)
            cand.push_back(i);
        // cout<<cand.back()<<"\n";
        return ways(n,cand.size());
    }
    
    ll ways(int n,int ns)
    {
        if(ns==0 && n)return 0;
        if(n==0)return 1;
        
        if(memo.count({n,ns}))return memo[{n,ns}];    
        ll a=0,b=0;
        
        a = ways(n,ns-1);
        if(n>=cand[ns-1])
            b = ways(n-cand[ns-1],ns);
            
        return memo[{n,ns}] = a+b;
        
    }
};
