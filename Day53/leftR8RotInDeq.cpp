// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

//Function to rotate deque by k places in anti-clockwise direction.
void left_Rotate_Deq_ByK(deque<int> &dq, int n, int k)
{
    while(k--)
    {
        dq.push_back(dq.front());
        dq.pop_front();
    }
}

//Function to rotate deque by k places in clockwise direction.
void right_Rotate_Deq_ByK(deque<int> &dq, int n, int k)
{
    while(k--)
    {
        dq.push_front(dq.back());
        dq.pop_back();
    }
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
        
        deque<int> deq;
        for(int i = 1; i <= n; i++)
        {
            int val;
            cin>>val;
            deq.push_back(val);
            
        }
        int rotateQuery, k;
        cin>>rotateQuery>>k;
        
        
        
        if(rotateQuery == 1)
            right_Rotate_Deq_ByK(deq, n, k);
            
        else left_Rotate_Deq_ByK(deq, n, k);
        
        
        for(auto itr = deq.begin(); itr != deq.end(); itr++)
            cout << *itr << " ";
        cout << endl;
    }
    return 0;
}

  // } Driver Code Ends