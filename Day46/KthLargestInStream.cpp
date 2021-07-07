// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to print kth largest element for each element in the stream.
    void kthLargest(int arr[], int n, int k)
    {   
        priority_queue<int,vector<int>,greater<int>> pq;
    	for(int i=0;i<n;i++)
    	{
    	    if(pq.size()<k)pq.push(arr[i]);
    	    else 
    	    {
    	   if(arr[i]>pq.top())
    	        pq.pop(),
    	        pq.push(arr[i]);
    	    }
    	    
    	    if(pq.size()<k)cout<<-1<<" ";
    	    else cout<<pq.top()<<" ";
    	}
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k, n;
		cin>>k>>n;
	    
	    int arr[n];
	    for(int i = 0; i<n ; ++i)
	        cin>>arr[i];
        Solution ob;
	    ob.kthLargest(arr, n, k);
	    cout<<endl;
	    
	    
	}
	return 0;
}
  // } Driver Code Ends