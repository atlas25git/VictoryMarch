// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        vector<char> veca,vecA;
        
        for(int i=0;i<n;i++)
		{
			int(str[i])<97?
			vecA.push_back(str[i]):
			veca.push_back(str[i]);
		}
        
        sort(veca.begin(),veca.end());
        sort(vecA.begin(),vecA.end());
        //cout<<veca.size()+vecA.size()<<endl;
        
       int vcA=0,vca=0;
		string answer="";
		
		//iterating over the given string.
		for(int i=0;i<n;i++)
		{
			int(str[i])<97?
			answer+=vecA[vcA++]:
			answer+=veca[vca++];
		}
		//returning the result.
		return answer;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}  // } Driver Code Ends