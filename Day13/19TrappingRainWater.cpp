// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Maintain 2 arrays denoting max from left and ri8
        //on the given array index
        //now while iterating substract arr[i], from the smaller
        //max of the 2;
        
        vector<int> L(n,0);
        vector<int> R(n,0);
        
        
        L[0]=arr[0];
        for(int i=1;i<n;i++)L[i]=max(arr[i],L[i-1]);
        
        R[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)R[i]=max(R[i+1],arr[i]);
        
        int water=0;
        for(int i=0;i<n;i++)water+=(min(L[i],R[i])-arr[i]);
        
        return water;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends