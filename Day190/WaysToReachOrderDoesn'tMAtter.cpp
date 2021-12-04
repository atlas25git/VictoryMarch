#define ll long long
class Solution
{   vector<int> memo;
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {   //memo.resize(m+1,-1);
        return dpCW(m);
        // return m/2+1;
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