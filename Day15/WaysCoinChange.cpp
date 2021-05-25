// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
    long long numberOfWays(int S[],int m,int n)
    {
        // if(v==0)return 1;
        // if(nc==0)return 0;
        
        // int exc = numberOfWays(c,nc-1,v);
        // if(v-c[nc-1]>=0)
        // exc += numberOfWays(c,nc,v-c[nc-1]);
        
        
        
        // return exc;
        
       long long int dp[n+1][m+1];
    for(long long int j=0;j<m+1;j++)dp[0][j]=1;
    for(long long int i=1;i<n+1;i++)dp[i][0]=0;
    
    for(long long int i=1;i<n+1;i++){
        for(long long int j=1;j<m+1;j++){
            dp[i][j]=dp[i][j-1]; 
            
            //For any given sum and array, when we are inncreasing the array elements, the combinations
            //would comprise of the previoously existing combinations.  
            
            if(S[j-1]<=i)
            //Here considering if the current coin value is less than the sum ,it could be included, and for the combination
            //we're looking for the available combinations with the sum minus selected coin value 
            //and the combinations ofr thus the resulting valuye of n
            dp[i][j] += dp[i-S[j-1]][j];
        }
    }
    return dp[n][m];
        }
        
    
};


// { Driver Code Starts.


int main() {
    
    //taking total count of testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //inserting coins to the array
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    Solution obj;
	    //calling function numberOfWays
	    cout<<obj.numberOfWays(coins,numberOfCoins,value)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends