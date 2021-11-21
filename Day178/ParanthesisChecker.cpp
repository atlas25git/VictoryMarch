class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        stack<char> b;
        b.push(s[0]);
        
        for(int i=1;s[i];i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                b.push(s[i]);
            else
            {
                if(s[i] == ')')
                {
                    if(!b.empty() && b.top()=='('){b.pop();continue;}
                    else return false;
                }
                else if(s[i] == '}')
                {
                    if(!b.empty() && b.top()=='{'){b.pop();continue;}
                    else return false;
                }
                else if(s[i] == ']')
                {
                    if(!b.empty() && b.top()=='['){b.pop();continue;}
                    else return false;
                }
            }
        }
        //cout<<b.size();
        return b.empty();
    }

};