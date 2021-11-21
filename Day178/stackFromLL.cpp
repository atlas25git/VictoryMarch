//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    StackNode* node = new StackNode(x);
    if(!top)top=node;
    //inserting at the head of LL
    //node is the new top, hence connecting it to the sub part
    else node->next = top,
        top = node;
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    if(!top)return -1;
    else{
        StackNode* olTop = top->next;
        int ans = top->data;
        delete(top);
        top = olTop;
        return ans;
    }
}