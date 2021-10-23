class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        for(int i=0;x[i];i++)
        {
            if(x[i]=='[' || x[i]=='{' || x[i]=='(')
                s.push(x[i]);
            else if(x[i]==']' || x[i] == '}' || x[i] == ')')
            {
                if(s.empty() || !cmp(s.top(),x[i]))
                    return false;
                else s.pop();
            }
        }
        if(s.empty())
            return true;
        else return false;
    }
    
    bool cmp(char b, char c)
    {
        if(b=='{' && c=='}')
            return true;
        else if(b=='[' && c==']')
            return true;
        else if(b=='(' && c == ')')
            return true;
        return false;
    }
};