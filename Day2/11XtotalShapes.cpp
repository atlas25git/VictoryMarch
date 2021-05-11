// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int r,c;
    void dfsMark(int i,int j,vector<vector<char>> &grid)
    {
        if(i>=0 && i<r && j>=0 && j<c){
        
        if(grid[i][j]=='X')
        {
            grid[i][j]='O';
            
            dfsMark(i+0,j+1,grid);
            dfsMark(i+0,j-1,grid);
            dfsMark(i+1,j+0,grid);
            dfsMark(i-1,j+0,grid);
        }
    }
    return;
    }
    
    int xShape(vector<vector<char>>& grid) 
    {
        //here basically we need to return no. of components
        //we traverse the adj matrix, on observing an X
        //we increment count of componenets
        //on this cell we call dfs, and all the places
        //reachable through this and possessing X, we mark them with O
        
        r = grid.size();
        c = grid[0].size();
        int count =0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                {
                    if(grid[i][j]=='X')
                    {
                        count++;
                        dfsMark(i,j,grid);
                    }
                }
        }
    
    return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends