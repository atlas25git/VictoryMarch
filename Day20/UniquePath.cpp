// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        int dp[a+1][b+1] = {0};
        
        for(int i=1;i<=a;i++)dp[i][1]=1;
        for(int i=1;i<=b;i++)dp[1][i]=1;
        
        for(int i=2;i<=a;i++){
            for(int j=2;j<=b;j++)
            {
                dp[i][j]=dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[a][b];
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends