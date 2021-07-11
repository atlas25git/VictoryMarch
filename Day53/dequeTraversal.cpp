// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


//Function to traverse the Deque and print the elements of it.
void printDeque(deque<int> Deq)
{
    while(!Deq.empty())
    {
        cout<<Deq.front()<<" ";
        Deq.pop_front();
    }
    cout<<endl;
    return;
}    
    

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        deque<int> Deq;
        for(int i = 0; i < n; i++)
        {
            int val;
            cin>>val;
            Deq.push_back(val);
        }
        printDeque(Deq);
        
    }
}
  // } Driver Code Ends