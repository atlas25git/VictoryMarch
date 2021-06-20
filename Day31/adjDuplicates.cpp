// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to remove pair of duplicates from given string using Stack.
    string removePair(string s)
    {
        stack<char>st;
            
        //pushing the first character of the string into the stack.
        st.push(s[0]);
        
        //iterating over the string.
        for(int i=1;i<s.length();i++)
        {
            //if current character of string is equal to the character at top 
            //of stack, we pop it from stack and continue iterating.
            if(!st.empty()&&s[i]==st.top())
            {
                st.pop();
                continue;
            }
            //else we push the current character into the stack.
            else
            {
                st.push(s[i]);
            }
        }
        string ans="";
        
        //adding all characters in the stack to the answer and returning it.
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};



// class Solution
// {
//     public:
//     //Function to remove pair of duplicates from given string using Stack.
//     string removePair(string s)
//     {   
//         string ans;
//         int count=1;
//         for(int i=1;s[i];i++)
//         {
//             if(s[i]==s[i-1])count++;
//             else{
                
//                 if(count&1)ans+=s[i-1];
//                 if(i==s.size()-1 && count == 0)ans+=s[i];
//                 count=1;
//             }
//         }
//         //cout<<count<<"-Count"<<"\n";
//         if(ans.size()==0 && count&1)
//         {   //cout<<"1"<<endl;
//             return ans+=s[0];
//         }
//         else if(count&1) return ans+s[s.size()-1];
//         else return ans;
//     }
// };

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        string ans = obj.removePair (s);
        if(ans=="")
            cout<<"Empty String"<<endl;
        else
            cout<<ans<<endl;
    }
    
	return 0;
}  // } Driver Code Ends