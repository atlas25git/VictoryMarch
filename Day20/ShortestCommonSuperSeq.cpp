// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(char* X, char* Y, int m, int n)
    {
        int dp[m+1][n+1]={0};
        
        for(int i=0;i<=m;i++)dp[i][0]=i;
        for(int i=0;i<=n;i++)dp[0][i]=i;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)
            {
                if(X[i-1] == Y[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]= 1+min(dp[i-1][j],dp[i][j-1]);
            }
            
        }
        return dp[m][n];
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    char X[10001], Y[10001];
    
    //taking total testcases
    cin >> t;
    while(t--){
    
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
    }
	return 0;
}

  // } Driver Code Ends