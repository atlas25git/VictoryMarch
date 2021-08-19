// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define ll long long
class Solution
{
    public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
    long long count(int c[],int n,int val)
    {
        vector<ll>dp(val+1,0);
        int m = 1e9+7;
        dp[0]=1;
        // /here instead of taking the min value we're adding up the stuff
        //of possible solutions
        //here it is considering the ordered pairs too
        // for(int v=1;v<=val;v++)
        //     {
        //         for(int i=0;i<n;i++)
        //         {
        //             int coin = c[i];
        //             if(coin<=v)
        //                 dp[v]+=dp[v-coin];
        //         }
        //     }
        
        
       // making sets whr order doesn't matter
       //simple analogy could be that here we're considering
       //the coins once, but in other case we were considering multiple
       //counts of it
        for(int i=0;i<n;i++)
        {
            int coin = c[i];
            for(int v=1;v<=val;v++)
                if(v>=coin)
                    dp[v]=(dp[v] + dp[v-coin]);
        }
            
        return dp[val];
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends