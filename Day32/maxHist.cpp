// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
       vector<long long> left(n,-1);
       vector<long long> right(n,n);
       
       stack<long long> s;
       
       for(int i=0;i<n;i++)
       {
           while(!s.empty() && arr[s.top()]>=arr[i])
                s.pop();
           if(!s.empty())
                left[i]=s.top();
            s.push(i);
            
       }
       
       stack<int> s1;
       
       for(int i=n-1;i>=0;i--)
       {
           while(!s1.empty() && arr[s1.top()]>=arr[i])
                    s1.pop();
            if(!s1.empty())
                right[i] = s1.top();
            s1.push(i);
       }
       
    //   for(auto x: left)cout<<x<<" ";
    //   cout<<"right:- "<<endl;
    //   for(auto x: right)cout<<x<<" ";
    
    long long ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        ans = max(ans,arr[i]*(right[i]-left[i]-1));
    }
    
       
       return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends