// The idea of using a universal steps count is futile as it will make 
// redundant increments for the members of the same level.

class Solution 
{   
    struct move{
        int i,j,k;
        // move():i(0),j(0),k(0){};
    };
    
    vector<int> dx = {1,1,-1,-1,2,2,-2,-2};
    vector<int> dy = {2,-2,2,-2,1,-1,1,-1};
    
    public:
    
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&kp,vector<int>&tp,int N)
	{
	   // kp[0]--,kp[1]--,tp[0]--,tp[1]--;
	    
	    auto isValid = [&N](int i,int j) -> bool
	    {
	        return (i>0 && j>0 && i<=N && j<=N);
	    };
	    
	    queue<move> q;
	    q.push({kp[0],kp[1],0});
	    int steps = 0;
	    vector<vector<bool>> vis(N,vector<bool>(N,0));
	    
	    while(!q.empty())
	    {   
	        bool flag = 0;
	        auto cr = q.front();
	        q.pop();
	        if(cr.i == tp.front() && cr.j == tp.back())
	        {
	            return cr.k;
	        }
            // steps++;	        
	        for(int i=0;i<8;i++)
	        {
	            int ni = cr.i + dx[i];
	            int nj = cr.j + dy[i];
	            
	            if(isValid(ni,nj) && !vis[ni-1][nj-1])
	            {   
	                if(!flag)
	               // steps++;
	               vis[ni-1][nj-1] = 1;
	                q.push({ni,nj,cr.k+1});
	            }
	        }
	    }
	    return -1;
	}
};