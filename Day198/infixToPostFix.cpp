class Solution
{   //Note:: In the case of '(' stack top will be '(' and hence of the lowest 
    //precedence i.e -1;
    public:
    //Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        stack <char> st;
        st.push('N');
        string cnvrt;
        for(int i=0;i<s.size();i++)
        {
            if(isNotOperator(s[i]))
                cnvrt += s[i];
                
            else if(s[i] == '(')
                st.push('(');
            else if(s[i] == ')')
            {
                while(st.top() != '(')
                {
                    char c = st.top();
                    st.pop();
                    cnvrt+=c;
                }
                st.pop();
            }
            else
            {
                while(prec(s[i]) <= prec(st.top()))
                {
                    cnvrt += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(st.top()!='N')
        {
            cnvrt+=st.top();
            st.pop();
        }
        return cnvrt;
    }
    
    bool isNotOperator(char c)
    {
        if((c>='a' && c<='z') || (c>='A' && c<='Z'))return true;
        return false;
    }
    
    int prec(char c)
    {
        if(c=='^')return 3;
        else if(c=='*' || c=='/')return 2;
        else if(c=='+' || c=='-') return 1;
        else return -1;
    }
};