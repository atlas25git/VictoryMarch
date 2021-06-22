// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<int, int> findRepeating(int *arr, int n){
        //code here
         if(n-(arr[n-1]-arr[0]) == 1){
             return {-1,-1};
         }
         
         int l=0,h=n-1;
         int mid=0;
         
         while(l<h)
         {
             mid=(l+h)/2;
             if(arr[mid]>=mid+arr[0])
                l=mid+1;
            
             else h = mid;
         }
         return {arr[mid],n-(arr[n-1]-arr[0])};
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    Solution obj;
	    pair<int, int> ans = obj.findRepeating(arr,n);
	    
	    cout << ans.first << " " << ans.second << endl;
	    
	}
	
}  // } Driver Code Ends