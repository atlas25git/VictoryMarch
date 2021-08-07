class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    
    int seg0andNeg(int arr[],int n)
    {
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=0)
                swap(arr[i],arr[j]),
                j++;
        }
        return j;
    }
    
    int fmp(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            if(abs(arr[i])-1 < n && arr[abs(arr[i])-1]>0)
                arr[abs(arr[i])-1] *=-1; 
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
                return i+1;
        }
        return n+1;
    }
    
    int missingNumber(int arr[], int n) 
    { 
        int shift = seg0andNeg(arr,n);
        return fmp(arr+shift,n-shift);
    } 
};

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int seg(int arr[],int n)
    {
        int j=0;
        for(int i=0;i<n;i++)
        {    
            if(arr[i]<=0)
                swap(arr[i],arr[j]),j++;
        }
        return j;
    }
    
    int msp(int arr[],int n)
    {
        for(int i=0;i<n;i++)
            {
                if(abs(arr[i])-1<n && arr[abs(arr[i])-1]>0)//unvisited
                    arr[abs(arr[i])-1] *= -1;
            }
            
            for(int i=0;i<n;i++)
                if(arr[i]>0)return i+1;
            
            return n+1;
    }
    
    int missingNumber(int arr[], int n) 
    { 
        //simple indices used to denote elements approach, just
        //segregation of negative elemrnt is the stuff added
        int shift = seg(arr,n);
        //cout<<shift<<"shift"<<endl;
        return msp(arr+shift,n-shift);
    } 
};

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends