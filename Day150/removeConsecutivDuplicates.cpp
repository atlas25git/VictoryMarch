class Solution
{
    public:
    //Function to remove consecutive duplicates from given string using Stack.
    string removeConsecutiveDuplicates(string s)
    {
        stack<char> st;
        int i = 0;
        while(s[i])st.push(s[i++]);
        string ans;
        while(!st.empty())
        {
            char a = st.top();
            st.pop();
            ans+=a;
            while(!st.empty() && st.top()==a)
                st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};