// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define ll long long

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        vector<ll> dp(s.size(),0);
        dp[0]=s[0]-'0';
        ll res=dp[0];
        int p=1e9+7;
        
        for(int i=1;s[i];i++)
        {
            int cr = s[i]-'0';
            
            dp[i] = (((i+1)*cr)%p //since the ith pos will be at unit's
                                    //and count is on a one based index
                                    //thus there'll be i+1 s[i]
                                    //also as in each substring len wise 1,2,3,4
                                    //there'll be a s[i] present in each 
                                    + (dp[i-1]*10)%p)%p;
                                    
            res = (res+dp[i])%p;
        }
        return res;
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}
  // } Driver Code Ends