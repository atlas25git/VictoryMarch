class Solution {
    //Since here we need to evaluate local minima/maxima
    // hence can't use the greater on right/left side as 
    // in max water collection problem. 
public:
    int largestRectangleArea1(vector<int>& heights) {
        int n = heights.size();
        vector<int> ls(n,-1),rs(n,n);
        
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            ls[i] = st.empty()?ls[i]:st.top();
            st.push(i);
        }
        
        while(!st.empty())st.pop();
        
        for(int i=n-1;i>-1;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            rs[i] = st.empty()?rs[i]:st.top();
            st.push(i);
        }
        
        int ans = INT_MIN;
        // for(auto x: ls)cout<<x<<" ";
        // cout<<endl;
        // for(auto x: rs)cout<<x<<" ";
        
        //Just doing a -1 because the diff already excludes 1 from the intial term, 
        //and hence for the term latter it has to be adjusted, also in case of former
        //next greater index array since indices are on 0 based index, and hence +1 adjusts
        //to give the exact count.
        //intializing the previous smaller array as -1 compensates when there is no previous smaller.
        //As no of bars on counted on 1 based index hence +1 index gives the pragmatic count.
        
        for(int i=0;i<n;i++)
            ans = max(ans,heights[i]*(rs[i] - ls[i] -1));
        
        return ans;
    }
    
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            vector<int> lt(n,-1),rs(n,n);
            stack<int> st;
            
            for(int i=n-1;i>-1;i--)
            {
                while(!st.empty() && heights[st.top()] >= heights[i])st.pop();
                if(!st.empty())
                    rs[i] = st.top();
                st.push(i);
            }
            while(!st.empty())st.pop();
            for(int i=0;i<n;i++)
            {
                while(!st.empty() && heights[st.top()] >= heights[i])st.pop();
                if(!st.empty())
                    lt[i] = st.top();
                st.push(i);
            }
            
            int ans = INT_MIN;
            for(int i=0;i<n;i++)
            {
                ans = max(ans,heights[i]*(rs[i] - lt[i] - 1));
            }
            
            return ans;
        }
};