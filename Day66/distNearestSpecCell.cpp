// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {1,-1,0,0};
    
    bool isValid(int i,int j, int r, int c)
    {
        return (i>-1 && j>-1 && i<r && j<c);
    }
    
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    //basically here we store all the filling points 
	    //and through each of them we apply flood fill algo,
	    //each time updating with the most optimal value;
	    int r=grid.size();
	    int c = grid[0].size();
	    queue<pair<int,int>> q;
	    vector<vector<int>>val(r,vector<int>(c,INT_MAX));
	    for(int i=0;i<r;i++)
	        for(int j=0;j<c;j++)
	            if(grid[i][j]==1)
	                val[i][j]=0,
	                q.push({i,j});
	   
	   while(!q.empty())
	   {
	       int i = q.front().first;
	       int j = q.front().second;
	       q.pop();
	       for(int d=0;d<4;d++)
	       {
	           int ni = i + dx[d];
	           int nj = j + dy[d];
	           
	           if(isValid(ni,nj,r,c))
	           {    //+1 becoz we moving a step at a time
	               if(val[ni][nj]>val[i][j]+1)
	                    val[ni][nj]=val[i][j]+1,
	                    q.push({ni,nj});
	           }
	       }
	       
	   }
	   return val;
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