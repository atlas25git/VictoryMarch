class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {   int m = 1e9+7;
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
};