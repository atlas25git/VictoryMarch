// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{   
    #define int1 long long int
    public:
    //Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string a){
        int cnt=0;
        for(auto x:a){
            if(x=='1')cnt++;
        }
        
        
        return cnt*(cnt-1)/2;
        
    }

};

// { Driver Code Starts.

int main()
{
    int t,n,count;
    string a;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin >> n;
        cin >> a;
        Solution obj;
        cout << obj.binarySubstring(n, a) << endl;
    }
}
  // } Driver Code Ends