// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    static bool sort1(pair<int,int> p1,pair<int,int> p2)
    {   
        if(p1.second==p2.second)
            p1.first<p2.first;
            
        return p1.second<p2.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> x;
        for(int i=0;i<n;i++)
            x.push_back({start[i],end[i]});
        
        sort(x.begin(),x.end(),sort1);
        int last=0,res=0;
        for(int i=0;i<n;i++)
        {
            if(x[i].first>last)
            res++,last=x[i].second;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends