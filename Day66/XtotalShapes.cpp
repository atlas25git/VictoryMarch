// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    void dfs(vector<vector<char>>& grid,int x,int y)
    {
        if(x<0||y<0||x>=grid.size()||y>=grid[x].size())
        return;
        
        //else mark all the adj cells which contain X
        if(grid[x][y]=='X')
            grid[x][y]='O',
            dfs(grid,x+1,y),
            dfs(grid,x-1,y),
            dfs(grid,x,y+1),
            dfs(grid,x,y-1);
    }
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        //the idea again here is to use flood fill algo, to mark
        //all the connected components, and in the complete traversal
        //of matrix we need to check for the disconnected comps.
        
        int r = grid.size();
        int c = grid[0].size();
        
        int i,j,ans=0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                if(grid[i][j]=='X')
                    ans++,
                    dfs(grid,i,j);
            }
    
        return ans;
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


//BFS Based Solution
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    bool isValid(int i,int j,int r, int c)
    {
        return (i>-1 && j>-1 && i<r && j<c);
    }
    
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> q;
        int ans=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(grid[i][j] == 'X')
                {
                    ans++;
                    q.push({i,j});
                    grid[i][j]='O';
                    
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        for(int k=0;k<4;k++)
                        {
                            int ni = x + dx[k];
                            int nj = y + dy[k];
                            
                            if(isValid(ni,nj,r,c))
                            {
                                if(grid[ni][nj]=='X')
                                    q.push({ni,nj}),
                                    grid[ni][nj]='O';
                            }
                        }
                    }
                }    
            }
    
        
    return ans;
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