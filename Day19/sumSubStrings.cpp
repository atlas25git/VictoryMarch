// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        long long dp[s.size()];
        dp[0]=int(s[0]-'0');
        long long res = 0, p=1e9+7;
        res=dp[0];
        
        //     For above example,
        //     sumofdigit[3] = 4 + 34 + 234 + 1234
        //   = 4 + 30 + 4 + 230 + 4 + 1230 + 4 //remember 4 here is the digit in question
        //   = 4*4 + 10*(3 + 23 +123)
        //   = 4*4 + 10*(sumofdigit[2])
        //     In general, 
        //     sumofdigit[i]  =  (i+1)*num[i] + 10*sumofdigit[i-1]
        
        for(int i=1;i<s.length();i++)
        {
            int c = int(s[i]-'0');
            
            //storing the no. formed at dp i from the ones behind it
            dp[i]=((( (i+1)*c)%p) + (dp[i-1]*10)%p)%p;
            
            res=(res+dp[i])%p;
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