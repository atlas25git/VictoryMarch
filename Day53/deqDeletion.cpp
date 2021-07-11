// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

//Function to erase the element from specified position X in deque.
void eraseAt(deque <int> &dq, int X)
{   auto it=dq.begin()+X;
    dq.erase(it);
        
}

//Function to erase the elements in range start (inclusive), end (exclusive).
void eraseInRange(deque<int> &dq, int X, int Y)
{   auto it=dq.begin()+X,it1=dq.begin()+Y;

    dq.erase(it,it1);
}

//Function to erase all the elements in the deque.
void eraseAll(deque<int> &dq)
{
   while(!dq.empty())
    dq.pop_back();
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
        
        int eraseQuery;
        cin>>eraseQuery;
        
        if(eraseQuery == 1)
        {
            int pos;
            cin>>pos;
            eraseAt(deq, pos);
        }
        else if(eraseQuery == 2)
        {
            int start, end;
            cin>>start>>end;
            eraseInRange(deq, start, end);
        }
        else
        {
            eraseAll(deq);
            
        }
        
        
        if(deq.empty())
            cout << "Empty";
        else
            {for(auto itr = deq.begin(); itr != deq.end(); itr++)
                cout << *itr << " ";}
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends