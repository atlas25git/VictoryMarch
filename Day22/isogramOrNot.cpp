// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if a string is Isogram or not.
    bool isIsogram(string s)
    {
        set<char> s1;
        for(int i=0;s[i];i++)s1.insert(s[i]);
        return (s1.size()==s.size());
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.isIsogram(s)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends