TC -> O(n)
SC -> O(h)
void IterativeInorder(Node *root)
{
    stack<Node*> st;
    Node* curr = root;
    //This loop will end when the node is Null and the stack is empty.
    while(curr || !st.empty())
    {
        while(curr)
        {
            st.push(curr);
            curr=curr->left;
        }
        //curr->left == NULL
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}