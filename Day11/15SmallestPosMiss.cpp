// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    
    int segragate(int* arr,int n)
    {  
        
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=0)swap(arr[i],arr[j++]);
        }
        return j;
    }
    
    int miss(int* arr,int n){
        
        
        
        for(int i=0;i<n;i++)
        {
            if(abs(arr[i])-1<n //abs
                && arr[abs(arr[i])-1]>0)
                    arr[abs(arr[i])-1]= -arr[abs(arr[i])-1];
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)return i+1;
        }
      
       return n+1;
        
    }
    
    
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        //we basically segragate the negatives first
        //now in the remaining reduced array, we mark index at arr[i]
        //negative to mark it's presence, given that it is in the range 1 to N
        //to mark negative and also keep it retrievable we just multiply
        //the no. present by -1 and use abs. for our calculations
        //if(n==1)if(arr[0]==1)return 2;else if(n==1 && arr[0]!=1) return 1;
        int n1 = segragate(arr,n);
        return miss(arr+n1,n-n1);
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