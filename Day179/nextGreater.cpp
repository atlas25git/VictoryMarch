class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        mp[nums2.back()] = -1;
        st.push(nums2.back());
        
        for(int i = nums2.size()-2;i>-1;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])st.pop();
            mp[nums2[i]] = st.empty()?-1:st.top();
            st.push(nums2[i]);
        }
        
        vector<int> ans;
        for(auto x: nums1)
            ans.push_back(mp[x]);
        return ans;
    }
};