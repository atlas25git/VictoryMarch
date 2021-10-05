class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> res;
        stack<Node*> s;
        Node* curr = root;
        while(curr || !s.empty())
        {
            while(curr)
                s.push(curr),
                curr=curr->left;
            
            curr = s.top();
            res.push_back(s.top()->data);
            s.pop();
            curr = curr->right;
        }
        return res;
    }
};