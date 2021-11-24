void convert(Node *head, TreeNode *&root) {
    if(!head)return;
    if(!head->next)
        {
            root = new TreeNode(head->data);
            return;
        }
    Node* curr= head;
    root = new TreeNode(head->data);
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode* fr = q.front();
        q.pop();
        
        if(curr->next){
            fr->left = new TreeNode(curr->next->data);
            curr = curr->next;
            q.push(fr->left);
        }
        if(curr->next)
        {
            fr->right = new TreeNode(curr->next->data);
            curr = curr->next;
            q.push(fr->right);
        }
    }
    return;
}