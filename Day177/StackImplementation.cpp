void MyStack :: push(int x)
{
    if(top>=1000)return;
    top++;
    arr[top] = x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    if(top==-1)return top;
    else
        {
            top--;
            return arr[top+1];
        }
}
