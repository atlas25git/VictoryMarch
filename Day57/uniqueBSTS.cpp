// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


#define ll long long
class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int n) 
    {   int m = 1e9+7;
        vector<ll> dp(n+1,0);
        //base case
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        //here the value of i has been ascertained as such to ensure that
        //at any given time the sum of nodes of subtrees is 1 less than the parent tree.
            for(int j=1;j<=i;j++)
                dp[i] = (dp[i]%m + dp[j-1]*dp[i-j]%m)%m;
            return dp[n];
    }
};

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	  // } Driver Code Ends