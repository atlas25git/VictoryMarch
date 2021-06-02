// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int arr[], int n) 
{
    long long dp[n][n];
    //base case: Leading Diagonal
    for(int i=0;i<=n-2;i++)dp[i][i+1]=max(arr[i],arr[i+1]);
    
    for(int g =3;g<n;g+=2)//to keep track of increasing gaps over the rows
    {   //i keeps track of the rows
        for(int i=0;i+g<n;i++)
        //filling the respective diagonal values belonging to a particular gap len
        {   
            int j=i+g;
            dp[i][j] = max(
                    arr[i] + min(dp[i+2][j],dp[i+1][j-1]),
                    arr[j] + min(dp[i+1][j-1],dp[i][j-2])
                );
        }
    }
    //discerned from the original fn call parameters
    return dp[0][n-1];
}

// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends