// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int incl_curr = arr[0]; 
        int excl_curr = 0; 
        
        int incl_prev = incl_curr; 
        int excl_prev = excl_curr; 
        
        for (int i = 1; i < n; i++)
        {
            //because if we're excluding current then both the
            //options are viable either to choose the element a position before
            //or not to include it, therefore we choose the max of both the contingencies
            excl_curr = max(incl_prev, excl_prev); 
            //coz in this case we can't select the left adj 
            incl_curr = excl_prev + arr[i]; 
            
            excl_prev = excl_curr;//this ascertains the max value  
            incl_prev = incl_curr; 
        }
        return max(excl_curr, incl_curr);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends