// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to insert all elements of the array in deque.
    deque<int> deque_Init(int arr[], int n)
    {
        deque<int> dq(arr,arr+n);
        // n--;
        // while(n>=0)
        //     dq.push_front(arr[n]),n--;
        return dq;
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
        
        int arr[n];
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution ob;    
        deque<int> res = ob.deque_Init(arr, n);
        for(auto x : res)
         cout << x << " ";
         
        cout << endl;
    }
}

  // } Driver Code Ends