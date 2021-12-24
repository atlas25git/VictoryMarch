vector<int> inOrder(Node *root) {
    vector<int> ans;
    if(!root)return ans;
    stack<Node*> st;
    Node* curr = root;
    while(curr || !st.empty())
    {
        while(curr)
            st.push(curr),
            curr = curr->left;
        Node* tp = st.top();
        ans.push_back(tp->data);
        st.pop();
        curr = tp->right;
    }
    return ans;
}