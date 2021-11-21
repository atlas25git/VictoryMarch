int min1 = INT_MAX;
//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n)
{
    stack<int> st;
    int i = 1;
    st.push(arr[0]);
    min1 = arr[0];
    
    while(i<n)
    {
        if(min1<arr[i])
            st.push(arr[i++]);
        else
            st.push(2*arr[i] - min1),
            min1 = arr[i++];
    }
    return st;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>st)
{
    while(!st.empty())
    {
        if(min1<st.top())
        {
            cout<<min1<<" ";
            st.pop();
        }
        else{
            cout<<min1<<" ";
            min1 = 2*min1 - st.top();
            st.pop();
        }
    }
}