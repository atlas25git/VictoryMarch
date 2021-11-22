class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
        
        //-1 compensates as the -1 that's been intialized in ls is inverted in sign
        //and in usual cases the use of -1 is implied as we've to exclude both the ends.
        for(int i=0;i<n;i++)
            ans = max(ans,heights[i]*(rs[i] - ls[i] -1));
        
        return ans;
    }
};