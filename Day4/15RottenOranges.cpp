// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    int r,c,cnt=0,res=0;
    
    vector<int> di = {-1,0,0,1};
    vector<int> dj = {0,-1,1,0};
    
    bool isValid(int i,int j)
    {
        return (i>=0 && j>=0 && i<r && j<c);
    }
    
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        //as given in the question, rotten oranges can 
        //rot the oranges adjacent to them in a nit time
        //thus we need to do a traversal BFS manner,
        //for every 1 that is adjacent in the given directions
        //rot it by marking it 2, then push it inside the queue to check
        //on it's adjacents.
        
        r=grid.size();
        c=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]>0)cnt++;
                if(grid[i][j]==2)q.push({i,j});
            }
        }
        
        while(!q.empty())
        {
            res++;
            int sizeq = q.size();
            //since all the rotten oranges would make others
            //rot simultaneously hence we use a forloop
            //to mark all the adjacent's rotting simultaneously
          
            for(int z=0;z<sizeq;z++){
            
            int i1 = q.front().first;
            int j1 = q.front().second;
            cnt--;
            q.pop();
            
            for(int i2 =0;i2<4;i2++)
            {
                if( isValid(i1+di[i2],j1+dj[i2]) &&
                    grid[i1+di[i2]][j1+dj[i2]] == 1)
                    {
                        grid[i1+di[i2]][j1+dj[i2]] = 2;
                        q.push({i1+di[i2],j1+dj[i2]});
                        
                    }
            }
            
        }
    }
    if(cnt==0) return (res-1);//coz even zero is a time instance;
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