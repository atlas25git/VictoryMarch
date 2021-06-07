// { Driver Code Starts
// C++ program Find concatenated string with 
// uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends



class Solution
{
    public:
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) 
    { 
        unordered_map<char, int> m; 
    	string res = ""; 
    
    	//using map to store all characters of s2 in map.
    	for (int i = 0; i < s2.size(); i++) 
    		m[s2[i]] = 1; 
    
    	//finding characters of s1 that are not present in s2
    	//and appending them to result.
    	for (int i = 0; i < s1.size(); i++) 
    	{ 
    		if (m.find(s1[i]) == m.end()) 
    			res += s1[i]; 
    		else
    			m[s1[i]] = 2; 
    	} 
    
    	//finding characters of s2 that are not present in s1
    	//and appending them to result.
    	for (int i = 0; i < s2.size(); i++) 
    		if (m[s2[i]] == 1) 
    			res += s2[i]; 
    			
    	if(res == "")
    	res = "-1";
    	
    	//returning the result.
    	return res; 
    } 
};


// { Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	Solution obj;
    	string res = obj.concatenatedString(s1, s2);
    	cout<<res<<endl;
	}
	return 0; 
}
  // } Driver Code Ends