// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

#define ll long long

class Solution {
  public:
    long long int nthFibonacci(long long int n){
        ll mod = 1e9+7;
        ll a;ll b;ll c=0;ll tmp;
        a=1,b=1;
        
        for(int i=2;i<n;i++)
            {
            c = (a%mod+b%mod)%mod,
            tmp = b,
            b = c,
            a = tmp,
            tmp=0;
            }
        if(n==1||n==2)return 1;
        return c%mod;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends