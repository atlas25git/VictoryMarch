class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> prevSmaller(n+1,-1),nextSmaller(n+1,n);
        stack<int> st;
        
        for(int i=0;i<n;i++)
            {while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            prevSmaller[i] = st.empty()?-1:st.top();
            st.push(i);}
            
        while(!st.empty())st.pop();
        
        for(int i=n-1;i>-1;i--)
            {while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            nextSmaller[i] = st.empty()?n:st.top();
            st.push(i);}
        
        vector<int> ans(n+1,0);
        
        //Now since in the window nextSmaller - prevSmaller - 1,
        //arr[i] is the smallest element hence it'll be marked
        //this can be envisioned as for len i+1 if say we've an answer
        //thereby for windows of len i, there could be 2 in the window 
        //i+1 hence the answer for i+1 would suffice well even for this 
        //case.
        for(int i=0;i<n;i++)
        {
            int len = nextSmaller[i] - prevSmaller[i] -1;
            ans[len] = max(ans[len],arr[i]);
        }
        
        //for the ones that haven't been filled it implies that those 
        //particular cells didn't contain the probable answer hence the element of 
        //window size+1 will suffice
      
      //won't work  
        // for(int i=1;i<=n;i++)
        //     ans[i] = max(ans[i],ans[i+1]);
            
        for (int i = n - 1; i >= 1; i--) 
            ans[i] = max(ans[i], ans[i + 1]);
        
        ans.erase(ans.begin());
        return ans;
    }
};