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
            //this basically what does is that it includes the combined 
            //states of zero sum subArrays with the intial zeros
            //demonstrated as |s1|0|s2|-s2|0
                            //-----=1
                            //-------------2
                            //      =======3
                            //hence the sum key incremented 3 times in the map.
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