vector<int> inOrder(Node *root) {
    stack<Node*> q;
    // q.push(root);
    Node* curr = root;
    vector<int> res;
    while(!q.empty() || curr)
    {
        while(curr)
            {
                q.push(curr),
                curr = curr->left;
            }
            
        curr = q.top();
        q.pop();
        res.push_back(curr->data);
        curr = curr->right;
    }
    return res;
}