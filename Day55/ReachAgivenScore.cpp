// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll count(ll n);

int main()
{
    //taking total testcases
	int t;
	cin>>t;
	
	while(t--)
	{
	    //taking the score
		ll n;
		cin>>n;
		
		//calling function count()
		cout << count(n) << "\n";
	}
	return 0;
}// } Driver Code Ends


//User function tempate for C++


//Function to find the number of distinct combinations to reach the given score.
ll count(ll n) 
{
    vector<int> dp(n+1,0);
    
    dp[0]=0;
    
    for(int i=3;i<=n;i++)
    {
        if(i-3==0)dp[i]+=1;
        else dp[i]+=dp[i-3];
    }
    for(int i=5;i<=n;i++)
     {
         if(i-5==0)dp[i]+=1;
        else dp[i]+=dp[i-5];
     }
    for(int i=10;i<=n;i++)
      {
         if(i-10==0)dp[i]+=1;
        else dp[i]+=dp[i-10];
      }
    return dp[n];
    
    
}