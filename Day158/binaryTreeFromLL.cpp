void convert(Node *head, TreeNode *&root) {
    queue<TreeNode*> q;
    root = new TreeNode(head->data);
    q.push(root);
    Node* curr = head;
    while(!q.empty())
    {
        TreeNode* Tnode = q.front();
        q.pop();
        
        if(curr->next)
        {
            Tnode->left = new TreeNode(curr->next->data);
            curr = curr->next;
            q.push(Tnode->left);
        }
        
        if(curr->next)
        {
            Tnode->right = new TreeNode(curr->next->data);
            curr = curr->next;
            q.push(Tnode->right);
        }
    }
    
    return;
}