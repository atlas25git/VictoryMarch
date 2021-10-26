#define ll long long

class Solution
{   
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<ll> left(n,-1);
        vector<ll> right(n,n);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
            if(!s.empty())
                left[i] = s.top();
            s.push(i);
        }
        
        stack<int> s1;
        for(int i=n-1;i>=0;i--)
        {
            while(!s1.empty() && arr[s1.top()]>=arr[i])s1.pop();
            if(!s1.empty())
                right[i] = s1.top();
            s1.push(i);
        }
        
        ll ans = INT_MIN;
        
        for(int i=0;i<n;i++)
            ans = max(ans,arr[i]*(right[i]-left[i]-1));
        
        return ans;
    }
};