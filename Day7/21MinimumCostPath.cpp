// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int r,c;
    bool isValid(int i,int j)
    {
        return (i>=0 && j>=0 && i<r && j<c);
    }
    
    vector<int> di ={0,0,1,-1};
    vector<int> dj ={1,-1,0,0};
    
    struct cell{
        int i;
        int j;
        int dis;
        bool operator<(cell new1)const{
            if(dis == new1.dis){
                if(j!=new1.j)return j<new1.j;
                return i<new1.i;
            }
            return dis<new1.dis;
        }
        
    };
    

    int minimumCostPath(vector<vector<int>>& grid) 
    {
        //1.Maintain a set,, with custom operator to define comparison based on
        //distance and in state of clash, its cordinates.
        //2.insert the source vertex in the set, obviously it'd have value 0,
        //3.run a loop till the set is totally empty basically a bfs traversal.
        //4.Meanwhile for the front element,i.e, closest to the current vertex,
        //check for its 4 neighbors, and update their distances if smaller is possible
        
        r = grid.size();
        c = grid[0].size();
        
        vector<vector<int>>dp(r,vector<int>(r,INT_MAX));
        
        set<cell> st;
        st.insert({0,0,0});
        dp[0][0] = grid[0][0];
        
        while(!st.empty()){
            auto fr = *st.begin();
            st.erase(st.begin());
            
            for(int i=0;i<4;i++)
            {
                int ni = fr.i + di[i];
                int nj = fr.j + dj[i];
                
                if(isValid(ni,nj) && dp[ni][nj]>dp[fr.i][fr.j] + grid[ni][nj])
                {
                    if(dp[ni][nj] != INT_MAX)//Case when there's some v in st through which 
                                            //we've included a path
                        st.erase(st.find({ni,nj,dp[ni][nj]}));
                    
                    dp[ni][nj] = dp[fr.i][fr.j] + grid[ni][nj];
                    st.insert({ni,nj,dp[ni][nj]});
                }
            }
        }
    
        return dp[r-1][r-1];
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