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
    
    bool isValid(int i,int j,int N)
    {
        return (i>-1 && j>-1 && i<N && j<N);
    }
    //     -2 -1 0  1  2
    // -2    |y |  | y|  
    // -1   y|  |  |  |y
    //  0    |  |x |  |
    //  1   y|  |  |  |y
    //  2    |y |  |y |
    
    vector<int> dx = {-2,-2,-1,-1,1,1,2,2};
    vector<int> dy = {1,-1,2,-2,-2,2,-1,1};
    
	int minStepToReachTarget(vector<int>&kp,vector<int>&tp,int N)
	{
	    //basically here our approach is to do a flood fill based bfs,
	    //in all the possible move directions, and thus store with each
	    //subsequent move a step incremental.
	    
	    //0 based index
	    kp[0]--;
	    kp[1]--;
	    tp[0]--;
	    tp[1]--;
	    
	    //making a str to manage steps alongwith the co-ordinates
	    queue<cell> q;
	    vector<vector<bool>>vis(N,vector<bool>(N,0));
	    
	    q.push({kp[0],kp[1],0});
	    while(!q.empty())
	    {
	        int i = q.front().i;
	        int j = q.front().j;
	        int steps = q.front().steps;
	        q.pop();
	        vis[i][j]=true;
	        
	        if(i == tp[0] && j == tp[1])
	            return steps;
	        
	        
	        for(int d=0;d<8;d++)
	        {
	            int ni = i + dx[d];
	            int nj = j + dy[d];
	            
	            if(isValid(ni,nj,N))
	            {
	                if(!vis[ni][nj])
	                {
	                    vis[ni][nj]=true;
	                    q.push({ni,nj,steps+1});
	                }
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