// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    
    static bool cmp(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.first==p2.first) 
            return p1.second<p2.second;
        return p1.first>p2.first;
    }
    
    vector<int> sortByFreq(int arr[],int n)
    {
        vector<pair<int,int>> y;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
                mp[arr[i]]++;
        
        for(auto x:mp)y.push_back({x.second,x.first});
        
        sort(y.begin(),y.end(),cmp);
        
        vector<int> res;
        for(int i=0;i<y.size();i++)
        {
            for(int j=0;j<y[i].first;j++)
                res.push_back(y[i].second);
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends