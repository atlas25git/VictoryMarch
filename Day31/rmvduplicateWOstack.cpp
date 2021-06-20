// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to remove consecutive duplicates from given string using Stack.
    string removeConsecutiveDuplicates(string s)
    {
        string ans;
        int count=1;
        for(int i=1;s[i];i++)
        {
            if(s[i]==s[i-1])count++;
            else{
                ans+=s[i-1];
            }
            count=1;
        }
        if(!ans.size())return ans+=s[0];
        return ans+s[s.size()-1];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends