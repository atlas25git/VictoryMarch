class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    //Since in any array there exist cycles of various lengths
	    //We first sort the array and then we calculate these cycle lens
	    //by marking vis.
	    vector<pair<int,int>> aug;
	    for(int i=0;i<nums.size();i++)
	        aug.push_back({nums[i],i});
    
	    sort(aug.begin(),aug.end());
	    vector<bool> vis(nums.size(),0);
	    
	    int ans = 0;
	    int cs = 0;
	    for(int i=0;i<vis.size();i++)
	    {
	        if(!vis[i] && aug[i].second != i)
	        {
	            int j = i;
	            cs = 0;
	            while(!vis[j])
	            {
	                vis[j] = 1;
	                j = aug[j].second;
	                cs++;
	            }
	            
	            ans += max(cs-1,0);
	        }
	    }
	    return ans;
	}
};