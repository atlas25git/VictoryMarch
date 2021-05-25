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
    long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
    {

        long long dp[value+1]={0};
        dp[0]=0;
        
        //initializing all values in array to INT_MAX.
        for(int i=1;i<value+1;i++)
        {
            dp[i]=INT_MAX;
        }
        
        //creating a list of coin denominations.
        vector<int> coinsSet;
        
        
        //pushing coin values in the list.
        for(int i=0;i<numberOfCoins;i++)
        {
            coinsSet.push_back(coins[i]);
        }
        
        //running a loop on list coinsSet of coin denominations.
        for(auto coin:coinsSet)
        {
            //running a loop from 1 to value.
            for(int i=1;i<value+1;i++)
            {
                if(i>=coin)
                {
                    //taking minimum of coins required for current index and 
                    //coins required for (i-coin value)+1.
                    dp[i]=min(
                        dp[i],
                        dp[i-coin]+1);
                }
            }
        }
        
        //if value cannot be obtained from the coin set then returning -1.
        //else returning minimum coins required to make the value.
        if (dp[value] == INT_MAX)
            return -1; 
        return dp[value];
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