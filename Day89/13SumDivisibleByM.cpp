// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//lass Solution{
class Solution{
	public:

		int DivisibleByM(vector<int>nums, int m){
			int n = nums.size();
		    if (n > m)
		        return 1;
		 
		    // This array will keep track of all
		    // the possible sum (after modulo m)
		    // which can be made using subsets of arr[]
		    // initialising boolean array with all false
		    bool DP[m];
		    memset(DP, false, m);
		 
		    // we'll loop through all the elements of arr[]
		    for (int i=0; i<n; i++)
		    {
		        // anytime we encounter a sum divisible
		        // by m, we are done
		        if (DP[0])
		            return true;
		 
		        // To store all the new encountered sum (after
		        // modulo). It is used to make sure that arr[i]
		        // is added only to those entries for which DP[j] 
		        // was true before current iteration.  
		        bool temp[m];
		        memset(temp,false,m);
		 
		        // For each element of arr[], we loop through
		        // all elements of DP table from 1 to m and
		        // we add current element i. e., arr[i] to
		        // all those elements which are true in DP
		        // table
		        for (int j=0; j<m; j++)
		        {
		            // if an element is true in DP table
		            if (DP[j] == true)
		            {
		                if (DP[(j+nums[i]%m)%m] == false)
		 
		                    // We update it in temp and update
		                    // to DP once loop of j is over
		                    temp[(j+nums[i]%m) % m] = true;
		            }
		        }
		 
		        // Updating all the elements of temp
		        // to DP table since iteration over
		        // j is over
		        for (int j=0; j<m; j++)
		            if (temp[j])
		                DP[j] = true;
		 
		 
		        // Also since arr[i] is a single element
		        // subset, arr[i]%m is one of the possible
		        // sum
		        DP[nums[i]%m] = true;
		    }
		 
		    return DP[0];
		}
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans  = ob.DivisibleByM(nums, m);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends