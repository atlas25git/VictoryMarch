void iterative_inorder(Node* root)
{
    stack<Node*> s;
    Node* curr = root;
    while(curr || !s.empty())
    {
        while(curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();//along the path the root will lie
        s.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }
}

//Iterative preorder:
//O(n) time and space
void iterativePreorder(Node* root)
{
    if(!root)return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        Node* curr = st.top();
        cout<<curr->key<<" ";
        st.pop();
        //reverse order of insertion due to LIFO 
        if(curr->right)st.push(curr->right);
        if(curr->left)st.push(curr->left);
    }
}

//O(n) time, and O(H)space
void iterativePreorder(Node* root)
{
    if(!root)return;
    stack<Node*> s;
    Node* curr = root;
    while(curr || !st.empty())
    {
        while(curr)
        {
            cout<<curr->data<<" ";
            if(curr->right)
                st.push(curr->right);
            curr = curr->left;
        }
        if(!s.empty()){
            curr = st.top();
            st.pop();
        }
    }
}