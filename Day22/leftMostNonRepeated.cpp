// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

class Solution
{
    public:
    //Function to find repeated character whose first appearance is leftmost.
    int repeatedCharacter (string s) 
    { 
        int fi[256];
        memset(fi,-1,sizeof(fi));
        int res=INT_MAX;
        for(int i=0;s[i];i++)
        {
            if(fi[s[i]]==-1)fi[s[i]]=i;
            else
                res=min(res,fi[s[i]]);
        }
        return res!=INT_MAX?res:-1;
        
    } 
};

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    Solution obj;
	    int index = obj.repeatedCharacter(s); 
        if (index == -1) 
            cout<<-1<<endl;
        else
            cout<<s[index]<<endl;
	}
	return 0;
}
  // } Driver Code Ends