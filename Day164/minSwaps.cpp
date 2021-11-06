class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    //Basically implementing cycle swap.
	    //swapping the array and storing with it, the originl
	    //index it was at.
	    //Now making a dfs call and hence storing the no. of swaps 
	    //required
	    
	    vector<pair<int,int>> graph;
	    
	    for(int i=0;i<nums.size();i++)
	    {
	           graph.push_back({nums[i],i});
	    }
	    sort(graph.begin(),graph.end());
	    
	    int ans = 0;
	    vector<int> vis(nums.size(),0);
	    for(int i=0;i<nums.size();i++)
	    {
	        if(vis[i])continue;
	        int j = i;
	        int cs = 0;
	        while(!vis[j])
	        {
	            vis[j] = true;
	            j = graph[j].second;
	            cs++;
	        }
	        ans += cs>0?cs-1:0;
	    }
	  return ans;
	}
};