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
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //Here our 2d array will contain at pos i,j
        //min len of supersequence for given len of strings x&y
        //here if char@i==char@j then we'll only need to add one element to 
        //the sequence and hence will check for the reduced state/
        //if both the char@1!=char@2 then we'll have to add 2 char to the min of the string
        //states of i-1,j and i,j-1
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                if(!i)
                    dp[i][j]=j;
                else if(!j)//only in the case of first col
                    dp[i][j]=i;
                else if(X[i-1]==Y[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j] = 1+ min(dp[i][j-1],dp[i-1][j]);
            return dp[m][n];
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends