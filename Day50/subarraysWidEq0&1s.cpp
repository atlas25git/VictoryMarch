// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        unordered_map<int,int> mp;
        int cs=0;
        for(int i=0;i<n;i++)
        {
            cs += (arr[i]==0)?-1:1;
            mp[cs]++;
        }
        long long int count=0;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            if(itr->second>1)
                count+=((itr->second)*(itr->second-1))/2;
                
        }
        if(mp.find(0)!=mp.end())
            count+=mp[0];
        return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends