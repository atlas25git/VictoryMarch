// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
        
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        
    bool isValid(int x,int y, int r,int c)
    {
        return (x>=0 && x<r && y>=0 && y<c);
    }
    
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //enqueue all the source cells
        //run till the queue is not empty
        //pop front, check for it's right movables
        //if found dest, return true else if blank then
        //mark it as source and enqueue
        
        queue<pair<int,int>> q;
        int r = grid.size();
        int c = grid[0].size();
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            //this queue contains only the source vertices
            for(int i=0;i<4;i++)
            {   
               if(!isValid(x+dx[i],y+dy[i],r,c)) continue;
               
               if(grid[x+dx[i]][y+dy[i]] == 2)return true;
               if(grid[x+dx[i]][y+dy[i]] == 3)
               {
                   grid[x+dx[i]][y+dy[i]] = 1;
                   q.push({x+dx[i],y+dy[i]});
               }
            }
        }
    
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends