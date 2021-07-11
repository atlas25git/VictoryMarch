// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    int find(int x,int parent[])
    {
        if(parent[x]==x)return x;
        else find(parent[x],parent);
    }
    
    //Function to merge two nodes a and b.
    void union_( int x, int y, int par[], int rank1[]) 
    {
        int xp = find(x,par);
        int yp = find(y,par);
        if(xp==yp)return;
        if(rank1[xp]<rank1[yp])
            par[xp]=yp;
        else if(rank1[xp]>rank1[yp])
            par[yp]=xp;
            else{
                par[yp]=xp;
                rank1[xp]++;
            }
    }   
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        return find(x,par) == find(y,par);
    }
};

// { Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
  // } Driver Code Ends