// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends




//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     int sn = s.size(),xn=x.size();
     for(int i=0;i<=sn-xn;i++)
     {int j=0;
         for(j=0;j<xn;j++)
            if(s[i+j]!=x[j])break;
            
            if(j==xn)return i;
            if(j)i+=j;
     }
     return -1;
     
}