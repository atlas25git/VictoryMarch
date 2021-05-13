// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    int r,c;
    
    vector<int> dx = {1,1,1,0,0,-1,-1,-1};
    vector<int> dy = {1,0,-1,1,-1,1,0,-1};
    
    bool isValid(int i, int j){
        return (i>=0 && j>=0 && i<r && j<c);
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        //here basically we count component lengths
        //in a bfs manner here we start by checking
        //for all the nodes that contain the value 1
        //to ensure this again isn't counted anyhow we mark current location as 
        //0, and thus update our answer to contain the max
        //we do not again intialize the selcted source as 1, coz
        //it won't make any affect as the components connected to it
        //have already been counted
        //and we do this consecutively for all the nodes that have been
        //counted as the part of some component
        
         r = grid.size();
         c = grid[0].size();
        queue <pair<int,int>> q;
        int ans = 0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
            {   
                if(grid[i][j]==1)
                {   
                    int cnt =1;
                    grid[i][j] = 0;
                    q.push({i,j});
                    
                    while(!q.empty()){
                        int r1 = q.front().first;
                        int c1 = q.front().second;
                        q.pop();
                        
                        for(int i1=0;i1<8;i1++)
                        {
                            if(isValid(r1+dx[i1], c1+dy[i1])
                                &&
                                grid[r1+dx[i1]][c1+dy[i1]] == 1)
                                {
                                    grid[r1+dx[i1]][c1+dy[i1]] = 0;
                                    cnt++;
                                    q.push({r1+dx[i1], c1+dy[i1]});
                                    
                                }
                        }
                        
                    }
                
                    ans = max(cnt,ans);
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
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends