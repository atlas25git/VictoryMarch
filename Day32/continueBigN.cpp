// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Generating the left min and right min index array:
        vector<int> left(n,-1),right(n,n-1);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
            //here my stack top contains index of element 
            //just smaller than arr[i] but before it
            if(!s.empty())
                left[i]=s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
            
            if(!s.empty())right[i]=s.top();
            
            s.push(i);
        }
        vector<int> ans(n,0);
        
        for(int i=0;i<n;i++)
        {
            int len = right[i]-left[i]-1;
            //cout<<"len: "<<len<<"ans[len]: "<<ans[len]<<"arr[i]: "<<arr[i]<<endl;
            ans[len] = max(ans[len],arr[i]);
            
        }
        
        for(int i=n-2;i>=0;i--)
         ans[i]=max(ans[i],ans[i+1]);
        
        for(auto x:ans)cout<<x<<" ";
        cout<<endl;
        for(auto x:right)cout<<x<<" ";
        cout<<endl;
        for(auto x:left)cout<<x<<" ";
        cout<<endl;
        return left;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends