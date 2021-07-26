// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    //here the basic idea behind our approach is that
	    //the elements not in correct place would have diff indices,
	    //we'll traverse them in a sorted order, and their seconds would 
	    //hold there curr index, further we will do a cycle detection from unvisited 
	    //nodes as in dfs manner, and would mark the elements of cycle visited.
	    //no. of swaps req will be cycle_length - 1;
	    
	    int n = nums.size();
	    vector<pair<int,int>> graph(n);
	    
	   for(int i=0;i<n;i++)
	    {
	       graph[i].first = nums[i];
	       graph[i].second = i;
	    }
	    sort(graph.begin(),graph.end());
	    vector<bool>vis(n,0);
	    int ans =0;
	    for(int i=0;i<n;i++)
	    {
	        if(vis[i] || i == graph[i].second)continue;
	        
	        int j=i;
	        int cs =0;
	        while(!vis[j])
	        {   
	            vis[j]=true;
	            j=graph[j].second;
	            cs++;
	        }
	        ans += cs>1?cs-1:0;
	    }
	    return ans;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends