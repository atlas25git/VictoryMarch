// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class SolutionN2Intution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n){
        
        //basically our solution approach here is that we start with 
        //0th index and check for he max reachable positions from this, either,
        //in subsequent jumps or from other cells by taking steps of 1;
        //but this is a O(n^2) approach as array elements are traversed for
        //all the ranges if {i,i+arr[i]}
    }
};


class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n)
    {
        //or approach here is simple, we check for the max possible
        //location that could be reached by a jump from the current index
        //and the steps it provides, however this is a greedy approach and
        //and we circumvent it by re intializing steps as the max range-i
        //as it is the expression we used.
        
        
        //base case:
        if(n<=1) return 0;
        if(arr[0]==0)return -1;
        
        int maxRange=arr[0];
        int steps=arr[0];
        int jumps=1;
        
        for(int i=1;i<n;i++){
            if(i==n-1)return jumps;
            
            maxRange = max(maxRange,i+arr[i]);
            steps--;//to keep a count of all the exploration
            
            if(steps==0){
                jumps++;
                if(i>=maxRange)
                return -1;
                
                steps = maxRange-i;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minimumJumps(arr, n)<<endl;    // Function to calculate minimum number of jumps
    }
    return 0;
}  // } Driver Code Ends