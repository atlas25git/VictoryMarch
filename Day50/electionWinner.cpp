// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int> mp;
        
        for(int j=0;j<n;j++)
            mp[arr[j]]++;
        
        int maxx =-1;
        string answer = "";
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>maxx)
                maxx=it->second,
                answer=it->first;
            
            else if(it->second == maxx && answer.compare(it->first)>0)
                answer=it->first;
        }
        vector<string> vec = {answer,to_string(maxx)};
        return vec;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends