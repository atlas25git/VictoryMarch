// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> rs(n,0);
        vector<int> cs(n,0);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                rs[i]+=matrix[i][j],//for i all the elements in row would be added in this loop.
                cs[j]+=matrix[i][j];//but here in each iteration one j'th col's 
                                    //element will be added
        int ms=0;
        for(int i=0;i<n;i++)
            ms=max(ms,rs[i]),
            ms=max(ms,cs[i]);
        
        int count =0;
        for(int i=0,j=0;i<n && j<n;)
        {
            int df = min(ms-rs[i], ms-cs[j]);
            matrix[i][j] +=df;
            rs[i]+=df;
            cs[j]+=df;
            
            count += df;
            
            if(rs[i]==ms)i++;
            if(cs[j]==ms)j++;
        }
        return count;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}

  // } Driver Code Ends