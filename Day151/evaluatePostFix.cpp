class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> s;
        for(int i=0;S[i];i++)
        {
            if(isdigit(S[i]))s.push(S[i]-'0');
            
            else
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                switch(S[i])
                {
                    case '+':s.push(val2+val1);break;
                    case '-':s.push(val2-val1);break;
                    case '*':s.push(val2*val1);break;
                    case '/':s.push(val2/val1);break;
                }
                
            }
        }
        return s.top();
    }
};
