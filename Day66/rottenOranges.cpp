// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {-1,1,0,0};
    
    bool isValid(int i,int j, int r, int c)
    {
        return (i>-1 && j>-1 && i<r && j<c);
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        //basically here we are doing a flood fill type of opr
        //we store locations of all the rotten oranges
        //and keep a count of all the oranges
        //we run a bfs flood fill and increment timeCounter every time
        //the loop runs, since all the oranges at unit dis would rot in 
        //a unit time hence so.
        //if all the oranges are rotten at the end we return the timeCounter,
        //else no sol.
        
        int tO = 0, tC=-1;
        queue<pair<int,int>>q;
        
        int r = grid.size();
        int c = grid[0].size();
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                {
                    if(grid[i][j]>0)//orange found
                        tO++;
                    if(grid[i][j]==2)
                        q.push({i,j});
                }
                
        while(!q.empty())
        {   
            //all the oranges at dis one from the nodes would be rotten ones
            tC++;
            int sz = q.size();//all the 2's color fillers
            for(int k=0;k<sz;k++)
            {
                int i = q.front().first;
                int j = q.front().second;
                //one Orange taken out 
                tO--;
                q.pop();
                
                for(int f=0;f<4;f++)
                    {
                        int ni = i + dx[f];
                        int nj = j + dy[f];
                        
                        if(isValid(ni,nj,r,c))
                        {
                            if(grid[ni][nj]==1)
                                grid[ni][nj]=2,
                                q.push({ni,nj});
                        }
                    }
                
            }
        }
        
        if(!tO)return max(tC,0);
        return -1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends