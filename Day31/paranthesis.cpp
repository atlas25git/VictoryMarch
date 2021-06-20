// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if opening and closing brackets are of same type.
    bool cmp(char b,char c)
    {
        if(b=='{' && c=='}')
            return true;
        else if(b=='[' && c==']')
            return true;
        else if(b=='(' && c==')')
            return true;
         return false;
    }
    
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        
        //iterating over the string.
        for(int i=0;i<x.size();i++)
        {
            //if opening bracket is encountered, we push it into stack.
            if(x[i]=='[' || x[i]=='{' || x[i]=='(')
                s.push(x[i]);
            
            //if closing bracket is encountered, we compare it with top of stack.
            else if(x[i]==']' || x[i]=='}' || x[i]==')')
            {
                //if top of stack has opening bracket of different
                //type, we return false.
                if(s.empty() || !cmp(s.top(),x[i])) 
                    return false;
                //else we pop the top element from stack.
                else
                    s.pop();
            }
        }
        //if stack becomes empty, we return true else false.
        if(s.empty())
            return true;
        else
            return false;
    }
};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends