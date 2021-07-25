// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    
    void revUtil(int l,int r, vector<long long>& arr,int n)
    {   
        if(r>=n)r=n-1;
        
        while(l<r){
            swap(arr[l],arr[r]);
            l++;r--;
        }
    }
    
    void reverseInGroups(vector<long long>& arr, int n, int k){
        int i=0,j=k;
        while(i<n)
        {
            revUtil(i,j-1,arr,n);
            i+=k,j+=k;
        }
        
        // int i=0,j=k-1;
        // while(i<n)
        // {
        //     revUtil(i,j,arr,n);
        //     i+=k,j+=k-1;
        // }
        
    }
};

// { Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
}

  // } Driver Code Ends