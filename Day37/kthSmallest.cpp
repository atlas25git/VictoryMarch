// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the kth smallest element in the array.
    
    int partition(int arr[],int l,int h)
    {
        int pivot=arr[h];
        int i=l-1;
        for(int j=l;j<h;j++)
        {
            if(arr[j]<pivot)
            {i++,
            swap(arr[i],arr[j]);}
        }
        swap(arr[i+1],arr[h]);
        return i+1;
    }
    
    int kthSmallest(int arr[], int n, int k)
    {
        int l=0,r=n-1;
        while(l<=r)
        {
            int p=partition(arr,l,r);
            if(p==k-1)
                return arr[p];
            else if(p>k-1)
                r=p-1;
            else 
                l=p+1;
        }
        return -1;
    }
};


// { Driver Code Starts.
int main(){
	
	int t;
	cin >> t;
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    
	    for(int i = 0; i<n; ++i)
	        cin>>arr[i];
	        
	    Solution ob;
	    cout << ob.kthSmallest(arr, n, k) << endl;
	    
	}
	return 0;
}  // } Driver Code Ends