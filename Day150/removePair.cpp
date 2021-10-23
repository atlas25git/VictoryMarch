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