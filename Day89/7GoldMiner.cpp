// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>>gt(n,vector<int>(m,0));
        
        for(int col = m-1;col>-1;col--)
            for(int row = 0;row<n;row++)
            {
                int right = col==m-1?0:gt[row][col+1];
                
                int ru = (row ==0|| col==m-1)?0:gt[row-1][col+1];
                int rd = (row==n-1||col==m-1)?0:gt[row+1][col+1];
                
                gt[row][col] = M[row][col] + 
                                max({right,ru,rd});
            }
    
        int res = gt[0][0];
        //SINCE IN THE PROBLEM STATEMENT ITSELF IT MENTIONS
        //THAT THE MINER COULD BE IN ANY ROW OF THE FIRST COL
        //HENCE WE LOOK OUT FOR THE MAX
        for(int i=n-1;i>-1;i--)
            res = max(res,gt[i][0]);
    
        return res;
    }
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends