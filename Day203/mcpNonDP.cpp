// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    // It is not possible to solve this problem using dynamic programming similar 
    // to previous problem because here current state depends not only on 
    // right and bottom cells but also on left and upper cells. 
    // We solve this problem using dijkstra's algorithm. 
    // Each cell of grid represents a vertex and neighbor cells adjacent vertices. 
    // We do not make an explicit graph from these cells 
    // instead we will use matrix as it is in our dijkstra's algorithm.
    
    int r=0,c=0;
    
    struct cell{
        int x,y,dis;
    };
    
    bool isValid(int i,int j)
    {
        return (i>-1 && j>-1 && i<r && j<c);
    }
    
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {-1,1,0,0};
    
    int minimumCostPath(vector<vector<int>>& grid)
    {
        r = grid.size();
        c = grid[0].size();
        
        vector<vector<int>> disCell(r,vector<int>(c,INT_MAX));
        
        auto cmp = [](cell a, cell b)->bool
        {   
            if(a.dis == b.dis)
            {
                if(a.x == b.x)return a.y<b.y;
                return a.x<b.x; 
            }
            return a.dis<b.dis;
        };
        
        set<cell,decltype(cmp)> diks(cmp);
        cell src = {0,0,0};
        diks.insert(src);
        disCell[0][0] = grid[0][0];
        
        while(!diks.empty())
        {
            auto curr = *diks.begin();
            diks.erase(diks.begin());
            
            int i = curr.x;
            int j = curr.y;
            int dis = curr.dis;
            
            for(int k=0;k<4;k++)
            {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if(isValid(ni,nj))
                {
                    if(disCell[ni][nj] > grid[ni][nj] + disCell[i][j])
                    {   
                        //in this case it'd already be present hence a case
                        //of duplicacy.
                        if(disCell[ni][nj] != INT_MAX)
                            diks.erase(diks.find({ni,nj,disCell[ni][nj]}));
                        disCell[ni][nj] = grid[ni][nj] + disCell[i][j];
                        diks.insert({ni,nj,disCell[ni][nj]});
                    }
                }
            }
            
        }
        return disCell[r-1][c-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends