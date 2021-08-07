// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        int ans = arr[high];
        while(low<=high)
        {
            int m = low + (high-low)/2;
            
            if(!m)ans = min(ans,arr[m]);
            
            
            //base cases
            if(m!=high && arr[m]>arr[m+1])
                {ans = min(ans,arr[m+1]);break;}
            if(m!=low && arr[m]<arr[m-1])
                {ans = min(ans,arr[m]);break;}
            
            if(arr[high]>arr[m])high=m-1;
            else low = m+1;
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends