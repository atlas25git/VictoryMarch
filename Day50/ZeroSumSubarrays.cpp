// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        
        unordered_map<int,int> mp;
        ll sum=0;
        ll c=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(!sum)c++;
            if(mp.count(sum)>0)
            //means in b/w elements became zero
            //.count method return 1 indicating presence
                c+=mp[sum];
            mp[sum]++;
        }
        return c;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends