// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    
    vector<int>dx = {1,-1,0,0};
	vector<int>dy = {0,0,1,-1};
	int r=0,c=0;
	//Function to check whether the cell is within the matrix bounds.
	bool isValid(int x, int y){
	    
	return (x >=0 and x < r and y >=0 and y < c);
	    
	}
    
    
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest (vector<vector<int>>grid)
	{
	    //here we basically apply bfs
	    //intially in a dp table we store all the locations marked 1
	    //their distance is stored as 0
	    //and these are inserted in the queue
	    //till the queue becomes empty we pop its front
	    //and check for its neighbors since, we already enqueued all the 
	    //1s now we just keep updating their respective positions 
	    //while incremening by 1 for each move
	    //we change distance of any adjacent cell iff the corresponding
	    //cell has a value greater than current, this way the risk of 
	    //administering 1's more than once is circumvented
	    
	    r = grid.size();
	    c = grid[0].size();
	    
	    vector<vector<int>> dp(r,vector<int>(c,INT_MAX));
	    queue<pair<int,int>> q;
	    
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++)
	        {
	            if(grid[i][j]==1)
	                {
	                dp[i][j]=0;
	                q.push({i,j});
	                }
	        }
	    }
	    while(!q.empty())
	    {
	        int i = q.front().first;
	        int j = q.front().second;
	        q.pop();
	        
	        for(int z=0;z<4;z++)
	        {
	            if(isValid( i+dx[z] , j+dy[z] ) 
	            && dp[ i + dx[z] ][j+ dy[z] ]>dp[i][j]+1)
	               { 
	                   dp[i+dx[z]][j+dy[z]] = dp[i][j] + 1;
	                    q.push({i+dx[z],j+dy[z]});
	               }
	        }
	    }
	    return dp;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends