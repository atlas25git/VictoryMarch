// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int a =0;
        int b=n-1;
        while(a<b)
        {
            if(M[a][b])
                //a knows b hence can't be a celebrity, 
                //hence next one
                a++;
                
            else 
                //checking for other mebers in the range
                //{n-1 to pruned search space as we've rejected a's 
                //which can't be celebrity.
                b--;
                
        }
        for(int i=0;i<n;i++)
        {   
            //checking for our calculated celebrity
            //if there is somebody he knows M[a][i]
            //and if there is somebody who doesn't know 
            //him !M[i][a]
            if( (i!=a)&&(M[a][i] || !M[i][a]))
                return -1;
        }
        return a;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends