void convert(Node *head, TreeNode *&root) {
    //1. Basicall the idea is to maintain some how the 
    //   order of 2*n,2*n+1, for n
    
    queue<TreeNode*> q;
    root = new TreeNode(head->data);
    q.push(root);
    Node* curr = head->next;
    
    while(!q.empty())
    {
        auto cr = q.front();
        q.pop();
        
        TreeNode* l,*r;
       
       if(curr)
       {
           l = new TreeNode(curr->data);
           curr = curr->next;
           cr->left = l;
       }
       if(curr)
       {
           r = new TreeNode(curr->data);
           curr = curr->next;
           cr->right = r;
       }
       if(cr->left)q.push(cr->left);
       if(cr->right)q.push(cr->right);
    }
    
}



void convert(Node *head, TreeNode *&root) {
    // curr=head;
    root = new TreeNode(head->data);
    queue<TreeNode*> q;
    q.push(root);
    // head = head->next;
    while(!q.empty())
    {
        TreeNode* it = q.front();
        q.pop();
        // Node* lt=NULL,*rt=NULL;
        
        if(head->next)
        {
            it->left = new TreeNode(head->next->data);
            head = head->next;
            q.push(it->left);
        }
        if(head->next)
        {
            it->right = new TreeNode(head->next->data);
            head = head->next;
            q.push(it->right);
        }
        
    }
    return;
}