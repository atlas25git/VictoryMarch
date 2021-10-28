class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        //our approach here is to first fill in lifo order all the left children
        //now we'll start printing them and at the first junction we'll get to right
        //children and hence this will continue;
        
        stack<Node*> st;
        Node* curr = root;
        vector<int> ans;
        while(curr || !st.empty())
        {
            //filling up the left side nodes
            while(curr)
                st.push(curr),
                curr = curr->left;
            
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }
        return ans;
    }
};