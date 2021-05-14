// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    
    struct cell{
        int i;
        int j;
        int steps;
    };
    
    bool isValid(int i,int j,int N){
        return (i>=0 && j>=0 && i<N && j<N);
    }
    vector<vector<int>>dxy = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    vector<int> di ={2,2,-2,-2,1,1,-1,-1};
    vector<int> dj ={1,-1,1,-1,2,-2,2,-2};
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	   //our approach here is to do a bfs traversal of graph
	   //whose nodes are represented by the cells
	   //we will compute steps required to reach the target position
	   //we will make a queue for the cells and
	   //will push initial position in it, then from this we'll enqueue
	   //all the possible paths that are possible from thie current cell
	   
	   vector<vector<bool>> vis(N,vector<bool>(N,false));
	  
	   KnightPos[0]--;
	   KnightPos[1]--;
	   TargetPos[0]--;
	   TargetPos[1]--;
	   
	   queue<cell> q;
	   
	   q.push({KnightPos[0],KnightPos[1],0});
	   
	   vis[KnightPos[0]][KnightPos[1]]=true;
	   
	   while(!q.empty())
	   {
	       int i1 = q.front().i;
	       int j1 = q.front().j;
	       int steps1 = q.front().steps;
	       q.pop();
	       
	       if(i1 == TargetPos[0] && j1 == TargetPos[1])return steps1;
	       
	       for(int z=0;z<di.size();z++)
	       {
	          int n_i = i1+di[z];
	          int n_j = j1+dj[z];
	           
	           if(isValid(n_i,n_j,N)
	                 &&
	               !vis[n_i][n_j] )
	               {
	                    q.push({n_i,n_j,(steps1)+1});
	                    vis[n_i][n_j]=true;
	               }
	       }
	       
	   }
	   
	 return -1;  
	}
};






// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends