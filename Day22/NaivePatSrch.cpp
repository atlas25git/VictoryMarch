// { Driver Code Starts
// C++ program for Naive Pattern 
// Searching algorithm 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if the given pattern exists in the given string or not.
    bool search(string pat, string txt) 
    { 
        int p = pat.size(),t=txt.size();
        for(int i=0;i<t;i++)
        {
            for(int j=0;j<p;j++)
                {
                    if(txt[i+j]!=pat[j])break;
                    if(j==p-1)return true;
                    
                }
            
        }
        return false;
    }
};


// { Driver Code Starts.

// Driver Code 
int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    string s, p;
	    cin >> s >> p;
	    Solution obj;
	    if(obj.search(p, s)) cout << "Yes"; else cout << "No"; cout << endl;
	}
	
	return 0; 
}
  // } Driver Code Ends