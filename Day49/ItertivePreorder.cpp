void iterativePreorder(Node* root)
{
    if(!root)return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        Node* curr = st.top();
        cout<<curr->data<<" ";
        st.pop();
        if(curr->right)st.push(curr->right);
        if(curr->left)st.push(curr->left);
    }
}

//Space-oPtimized/
// O(h)
void iterativePreOrder(Node* root)
{
    if(!root)return;
    stack<Node*> st;
    Node* curr = root;
    while(curr || !st.empty())
    {
        whie(curr)
        {
            cout<<curr->key<<" ";
            if(curr->right) st.push(curr->right);
            curr = curr->left;
        }
        if(!st.empty())
            {
                curr=st.top();
                st.pop();
            }
    }
}