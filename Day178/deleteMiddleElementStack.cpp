class Solution 
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid_util(stack<int>&s, int sizeOfStack, int current)
    {
        if(current == sizeOfStack/2)
        {
            s.pop();
            return;
        }
        
        int x = s.top();
        s.pop();
        current++;
        deleteMid_util(s,sizeOfStack,current);
        
        s.push(x);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        deleteMid_util(s,sizeOfStack,0);
    }
};