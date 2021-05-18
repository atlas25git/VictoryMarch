// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    
    void rotUtil(int l,int r,int arr[],int n){
        while(l<r){
            swap(arr[l],arr[r]);
            l++,r--;
        }
    }
    
    void rotateArr(int arr[], int d, int n){
        
        rotUtil(0,d-1,arr,n);
        rotUtil(d,n-1,arr,n);
        rotUtil(0,n-1,arr,n);
        
        //for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        //cout<<endl;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}  // } Driver Code Ends