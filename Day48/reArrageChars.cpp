// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    
    public:
    
    struct key{
        int c;
        char ch;
        
        bool operator<(const key &k) const
        {
            return c<k.c;
        }
        
    };
    
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
    string rearrangeString(string str)
    {
        
        int count[26] = {0};
    	priority_queue<key> pq;
    	for(int i=0;str[i];i++)
    	{
    	    count[str[i] - 'a']++;
    	}
    	for(int i=0;i<26;i++)
    	{   if(count[i])
    	    pq.push(key{count[i],char(int('a')+i)});
    	    
    	}
    	
    	str = "";
    	key prev{-1,'#'};
    	
    	
    	while(!pq.empty())
    	{
    	    key t = pq.top();
    	    pq.pop();
    	    str = str + t.ch;
    	    //cout<<t.ch<<"t,.ch"<<endl;
    	    if(prev.c>0)
    	        pq.push(prev);
    	   
    	    t.c--;
    	    prev=t;
    	    
    	    
    	}
    	return str;
    }
};

// { Driver Code Starts.

int checker(string str, string pat)
{
    int freq[26];
    for(int i=0;i<26;i++)
        freq[i]=0;
    if(str.length()!=pat.length())
        return 0;
    for(int i=0;i<str.length();i++)
    {
        freq[str[i]-97]--;
        if(pat[i]<97 || pat[i]>122)
            return 0;
        freq[pat[i]-97]++;
    }
    for(int i=0;i<26;i++)
        if(freq[i]!=0)
            return 0;
    for(int i=0;i<pat.length()-1;i++)
        if(pat[i]==pat[i+1])
            return 0;
    return 1;
}

int main()
{
	int t;
	cin>>t;
	cin.ignore(INT_MAX, '\n');
	while(t--)
	{
	    string str,ret;
	    cin>>str;
	    Solution ob;
	    ret = ob.rearrangeString(str);
	    cout << checker(str, ret) << endl;
	}
    return 0;
}  // } Driver Code Ends