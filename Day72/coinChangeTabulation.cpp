// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Complete this function

class Solution
{
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    long long minimumNumberOfCoins(int coins[],int n,int v)
    {
        //tabulation based sol
        vector<int> dp(v+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=v;i++)
        {
            //foreach incremental val we check for all possible coins
            for(int j=0;j<n;j++)
            {
                if(coins[j]<=i)
                {
                    if(dp[i-coins[j]]!=INT_MAX)
                        dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
    
        return dp[v]==INT_MAX?-1:dp[v];
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
	    
	    //taking value of each coin
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    Solution obj;
	    //calling function minimumNumberOfCoins()
	    int answer=obj.minimumNumberOfCoins(coins,numberOfCoins,value);
	    
	    //printing "Not Possible" if answer is -1
	    //else printing answer
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends