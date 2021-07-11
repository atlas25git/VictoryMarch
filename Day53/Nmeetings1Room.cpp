// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    
    static bool sort1(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.second == p2.second)  
            return p1.first<p2.first;
        return p1.second<p2.second;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> s;
        for(int i=0;i<n;i++)
            s.push_back({start[i],end[i]});
        
        sort(s.begin(),s.end(),sort1);
        int last=0,res=0;
        for(int i=0;i<n;i++)
        {
            if(s[i].first>last)
                res++,last=s[i].second;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends