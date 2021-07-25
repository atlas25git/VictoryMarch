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
	    //Basically our idea is here to count the cycle length
	    //of array elements along with their respective positions and the 
	    //swap it'd take to reach the correct place
	    //any no. to be fixed right at it's location would require some
	    //swaps in cyclical order thereby fixing all others as ell
	   
	    int n=nums.size();
	    vector<pair<int,int>> cmb(n);
	    
	    for(int z=0;z<n;z++)
	    {
	        cmb[z].first = nums[z];
	        cmb[z].second = z;
	    }
	    
	    sort(cmb.begin(),cmb.end());
	    vector<bool> vis(n,false);
	    
	    int res=0;
	    for(int i=0;i<n;i++)
	    {   
	        if( !vis[i] && i != cmb[i].second)
	        {   
	            //cout<<"C<<endl"<<endl;
	            int cs=0;
	            int j=i;
	            
	            while(!vis[j])
	            {
	                vis[j]=true;
	                j=cmb[j].second;
	                cs++;
	               //cout<<cs<<":::"<<"\n";
	            }
	            
	            //cout<<cs<<endl;
	            (cs>0)?(res+=(cs-1)):res+=0;
	        }
	        //else continue;
	        
	    }
	    return res;
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