// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        //we need to give the count of maximum non overlapping
        //intervals
        vector<pair<int,int>> act(n);
        for(int i=0;i<n;i++)
        {
            act[i].first = end[i];
            act[i].second = start[i];
        }
        //sorting
        sort(act.begin(),act.end());
        int res=1,last=act[0].first;
        for(int i=1;i<n;i++)
        {
            if(act[i].second > last)
                res++,last = act[i].first;
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