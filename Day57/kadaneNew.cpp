// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to return the maximum sum without adding adjacent elements.
    long long maximumSum(int arr[], int n)
    {
        //all elements neg:
        int msf = INT_MIN;
        int counter=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)counter++;
            msf = max(msf,arr[i]);
        }
        if(counter==n)return msf;
        vector<int> dp(n+1,0);
        dp[0]=max(arr[0],0);
        dp[1]=max(arr[1],dp[0]);
        msf=INT_MIN;
        for(int i=2;i<n;i++)
        {
            dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
            msf=max(msf,dp[i]);
        }
        return msf;
    }
    
    
};

// { Driver Code Starts.


int main() {
    
    //taking total testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking size of array
	    int sizeOfArray;
	    cin>>sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    //inserting elements in the array
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    Solution ob;
	    //calling function maximumSum()
	    cout<<ob.maximumSum(arr,sizeOfArray)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends