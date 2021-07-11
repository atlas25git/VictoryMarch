// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int rank1[100001];


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to merge two nodes a and b.
    
    int find(int x, int par[])
        {
            if(par[x]==x)return x;
            return find(par[x],par);
        }
    
    void unionNodes( int a, int b, int par[], int rank1[], int n) 
    {
        int ap=find(a,par);
        int bp=find(b,par);
        
        if(ap==bp)return;
        if(rank1[ap]>rank1[bp])par[bp]=ap;
        else if(rank1[ap]<rank1[bp])par[ap]=bp;
        else
        {
            par[bp]=ap;
            rank1[ap]++;
        }
    }
    
    //Function to determine number of connected components.
    int findNumberOfConnectedComponents( int n, int arr[], int rank1[]) 
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(find(i,arr)==i)cnt++;
        }
        return cnt;
    }
};

// { Driver Code Starts.



int main() {
    int t;
    cin>>t;

    while(t--) {
        
        //taking number of nodes
        int n;
        cin>>n;

        //initializing parent array and
        //rank array
        for(int i=1; i<=n; i++) {
            arr[i] = i;
            rank1[i] = 1;
        }

        //taking number of queries
        int q;
        cin>>q;
        Solution obj;
        while(q--) {
            int a,b;
            cin>>a>>b;
            
            //calling unionNodes() function
            obj.unionNodes(a,b, arr, rank1, n);
        }

        //calling function findNumberofConnectedComponents()
        cout<<obj.findNumberOfConnectedComponents(n, arr, rank1)<<endl;
    }
    return 0;
}  // } Driver Code Ends