void twoStacks :: push1(int x)
{
    //if there is space between the top of both stacks 
    //we push the element at top1+1.
    if (top1 < top2 - 1)
    {
       top1++;
       arr[top1] = x;
    }
 
}

//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
   //if there is space between the top of both stacks 
    //we push the element at top2-1.
   if (top1 < top2 - 1)
   {
       top2--;
       arr[top2] = x;
   }
 
}

//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
   //if top1==-1, stack1 is empty so we return -1 else we 
   //return the top element of stack1.
   if (top1 >= 0 )
   {
      int x = arr[top1];
      top1--;
      return x;
   }
   else
      return -1;
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
   //if top2==size of array, stack2 is empty so we return -1 else we 
   //return the top element of stack2.
   if (top2 < size)
   {
      int x = arr[top2];
      top2++;
      return x;
   }
   else
      return -1;
}