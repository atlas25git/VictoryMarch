class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> res;
        Node* curr = root;
        stack<Node*> st;
        while(curr || !st.empty())
        {
            while(curr)
            st.push(curr),
            curr = curr->left;
            
            curr = st.top();
            st.pop();
            res.push_back(curr->data);
            curr = curr->right;
        }
        return res;
    }
};