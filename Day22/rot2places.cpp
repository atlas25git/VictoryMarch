// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int n1=str1.size(),n2=str2.size();
        if(n1!=n2)return false;
        if(n1<=2)return(str1==str2);
        
        string cw,ccw;
        
        ccw = str2.substr(n2-2,n2) + str2.substr(0,n2-2);
        cw = str2.substr(2,n2) + str2.substr(0,2);
        
        return (str1.compare(cw)==0||str1.compare(ccw)==0);
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends