class Solution
{
    public:
    //Function to remove pair of duplicates from given string using Stack.
    string removePair(string s)
    {
        stack<char> st;
        int i = 1;
        st.push(s[0]);
        
        while(s[i])
        {
            while(i<s.size() && !st.empty() && st.top() == s[i])st.pop(),i++;
            if(i>=s.size())break;
            st.push(s[i++]);
        }
        
        string ans;
        while(!st.empty()){ans+=st.top();st.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};