// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int sumExists(int arr[], int N, int sum);

 // } Driver Code Ends
//User function Template for C++


//You need to complete this function.
//Function to check if there is a pair with the given sum in the array.
int sumExists(int arr[], int N, int sum)
{
     unordered_set<int> s;
    int temp=0;
    for(int i=0;i<N;i++)
    {
        temp = sum-arr[i];
        if(temp>=0 && s.count(temp)!=0)return 1;
        
        s.insert(arr[i]);
    }
    return 0;
}

// { Driver Code Starts.

int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int N;
        cin>>N;
        
        int arr[N];
        
        for(int i=0;i<N;i++)
        cin>>arr[i];
        int sum;
        cin>>sum;
        
        cout<<sumExists(arr,N,sum)<<endl;
        
    }
	return 0;
}
  // } Driver Code Ends