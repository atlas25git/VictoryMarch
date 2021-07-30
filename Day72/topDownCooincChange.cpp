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
    vector<int> dp;
    
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
                    int subres;
                    if(dp[v-c[i]]==INT_MAX)
                        subres = fill(c,n,v-c[i]);
                    else 
                        subres = dp[v-c[i]];
                        
                    if(subres!=INT_MAX)//sol exists
                    {
                        res = min(res,subres+1);
                        dp[v-c[i]]=res;
                    }
                }
            }
            return res;
    }
    
    long long minimumNumberOfCoins(int c[],int n,int v)
    {   
        dp.resize(n+1);
        dp.assign(n+1,INT_MAX);
        //cout<<dp.size()<<endl;
        // here basically we perform a complete search
        //and thus maintain 2 markers, if it is 0 then it's a valid sol
        //thus we store the no of coins req in our second marker.
        //and at every step we check for all the coins smaller than the curr
        //value.
        
        int res=0;
        res = fill(c,n,v);
        return res==INT_MAX?0:res;
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