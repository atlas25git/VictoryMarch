void convert(Node *head, TreeNode *&root) {
    
    if(!head){root=NULL;return;}

    queue<TreeNode*> q;
    
    root = new TreeNode(head->data);
    
    q.push(root);
    
    head=head->next;
    //basically the queue here is helping us maintain the distance
    //pf 2*i,2*i+1 meanwhile also having at hand the nodes in between
    while(head)
    {
       TreeNode* t = q.front();
       q.pop();
       
       TreeNode *l=NULL,*r=NULL;
        
       l = new TreeNode(head->data);
       head = head->next;
       q.push(l);
       if(head)
       {
           r = new TreeNode(head->data);
           head = head->next;
           q.push(r);
       }
       
       t->left = l;
       t->right = r;
    }
}
