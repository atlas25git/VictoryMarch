// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // Function to count number of Ones
    // arr: input array 
    // N: size of input array
    
    int countRec(int* arr,int N,int l,int h)
    {   
        int mid=(h+l)/2;
        
        
        if(arr[mid]==1 && mid+1<N && arr[mid+1]==0)return mid+1;
        
        else if(arr[mid]==1 && mid+1<N && arr[mid+1]==1)countRec(arr,N,mid+1,h);
        
        else if(arr[mid]==0)
            {   
                if(mid==0) return 0;
                else
                countRec(arr,N,l,mid-1);
            }
    }
    
    int countOnes(int arr[], int N)
    {
        
        //destination i==1 && i+1 == 0
        int h=N-1,l=0;
        if(arr[N-1]==1)return N;
        //mid=(h-l)/2;
        //if(arr[0]==0)return 0;
        return countRec(arr,N,l,h);    
        
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
        int *arr = new int[n]; 
        for(int i = 0; i < n; i++)
            cin>>arr[i];
            
        Solution ob;
        cout <<ob.countOnes(arr, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends