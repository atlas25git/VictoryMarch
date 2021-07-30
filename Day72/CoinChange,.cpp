//recursive solutin
class Solution
{
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    int fill(int c[],int n, int v)
    {
        //base marker
        if(!v)return 0;
        int res = INT_MAX;
        
        //performming a complete search
        for(int i=0;i<n;i++)
            {
                if(c[i]<=v)
                {
                    int subres = fill(c,n,v-c[i]);
                    if(subres!=INT_MAX)//sol exists
                    {
                        res = min(res,subres+1);
                    }
                }
            }
            return res;
    }
    
    long long minimumNumberOfCoins(int c[],int n,int v)
    {
        // here basically we perform a complete search
        //and thus maintain 2 markers, if it is 0 then it's a valid sol
        //thus we store the no of coins req in our second marker.
        //and at every step we check for all the coins smaller than the curr
        //value.
        
        int res=0;
        res = fill(c,n,v);
        return res;
    }
}; 
 
 
   int fill(int coins[],int n,int v,int& res)
    {
        if(!v)return 0;
        int mark = INT_MAX;
        
        for(int i=0;i<n;i++)
            {
                if(coins[i]<=v)
                {
                    int sres = fill(coins,n,v-coins[i],res);
                    if(sres!=INT_MAX)
                        mark = min(mark,sres+1)
                        ,res=sres;
                }
            }
            return mark;
    }
    
    long long minimumNumberOfCoins(int coins[],int n,int v)
    {
        int res =0;
        return fill(coins,n,v,res);
        //return res;
    }