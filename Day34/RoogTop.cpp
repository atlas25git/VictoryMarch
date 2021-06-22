// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int a[], int n)
    {
        int c=0;
        int m=0;
        
        //iterating over the array elements from index 1(2nd element).
        for(int i=1;i<n;i++)
        {
            //if current element is greater than previous element, we gain an
            //increase in altitude so we increment the counter.
            if(a[i]>a[i-1])
                c++;
            
            //else we have to compare the counter with max value stored.
            else
            {
                //updating the max value and making the counter 0 again.
                m = max(c,m);
                c = 0;
            }
        }
        m=max(c,m);
        
        //returning the maximum value.
        return m;
    }
};

// { Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    Solution ob;
	    cout << ob.maxStep(a, n) << endl;
	}
	return 0;
}  // } Driver Code Ends