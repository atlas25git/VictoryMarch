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
        stack<char> st;
        st.push(s[0]);
        string ans;
        for(int i=0;s[i];i++)
        {
            if(st.top()==s[i])continue;
            else{
                ans+=st.top();
                st.pop();
                st.push(s[i]);
            }
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