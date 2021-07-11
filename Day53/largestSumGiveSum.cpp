// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        if(sum==0)
            {
                if(n==1)
                    return "0";
                    else {
                        string r;
                        while(n--)
                            r+="0";
                        return r;
                    }
            }
        if(sum>9*n)return "-1";
        string res;
        
        for(int i=0;i<n;i++)
        {
            if(sum>=9)
            res+="9",
            sum-=9;
            else {
                res+=to_string(sum);
                sum=0;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends