class Solution
{
    public:
    //Function to remove consecutive duplicates from given string using Stack.
    string removeConsecutiveDuplicates(string s)
    {
        int i = 1;
        stack<char> st;
        st.push(s[0]);
        while(s[i])
        {   
            while(!st.empty() && i<s.size() && st.top() == s[i])i++;
            if(i>=s.size())break;
            st.push(s[i]);
        }
        
        string ans;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
