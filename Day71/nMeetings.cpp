// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> act(n);
        for(int i=0;i<n;i++)
        {
            act[i].second = start[i];
            act[i].first = end[i];
        }
        sort(act.begin(),act.end());
        int count=1,last  = act[0].first;
        for(int i=1;i<n;i++)
        {
            if(last<act[i].second)
                count++,
                last = act[i].first;
        }
        
        return count;
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


class Solution
{
    public:
    
    //comparator function used in sorting the list of pairs 
    //according to increasing order of the finish time.
    static bool pairCompare(const pair<pair<int, int>, int> &a,
                     const pair<pair<int, int>, int> &b) 
    {
        if (a.first.second != b.first.second) {
            return a.first.second < b.first.second;
        }
        return a.second < b.second;
    }
    
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n) 
    {
    
        vector<pair<pair<int, int>, int>> x;
     
        //pushing the pair of starting and finish time and their 
        //index as pair in another list.
        for (int i = 0; i < n; i++) 
        x.push_back({{start[i], end[i]}, i + 1});
    
        //sorting the list.
        sort(x.begin(), x.end(), pairCompare);
        int last = 0;
        int res = 0;
        
        for (int i = 0; i < n; i++)
        {
            //if the start time of this meeting is greater than or equal
            //to the finish time of previously selected meeting then 
            //we increment the counter and update last.
            if (x[i].first.first > last) 
            {
                res++;
                last = x[i].first.second;
            }
        }
        //returning the counter.
        return res;
    }
};