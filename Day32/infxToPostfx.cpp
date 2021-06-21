int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
}
 
// A utility function to return
// precedence of a given operator
// Higher returned value means
// higher precedence
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}
 
 
// The main function that
// converts given infix expression
// to postfix expression.
char* infixToPostfix(char* exp)
{
    int i, k;
 
    // Create a stack of capacity
    // equal to expression size
    struct Stack* stack = createStack(strlen(exp));
    
    for (i = 0, k = -1; exp[i]; ++i)
    {
         
        // If the scanned character is
        // an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
         
        // If the scanned character is an
        // â€˜(â€˜, push it to the stack.
        else if (exp[i] == '(')
            push(stack, exp[i]);
         
        // If the scanned character is an â€˜)â€™,
        // pop and output from the stack
        // until an â€˜(â€˜ is encountered.
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
                pop(stack);
        }
        else // an operator is encountered
        {
            while (!isEmpty(stack) &&
                 Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
 
    }
 
    // pop all the operators from the stack
    while (!isEmpty(stack))
        exp[++k] = pop(stack);
 
    exp[++k] = '\0';
    return exp;
}