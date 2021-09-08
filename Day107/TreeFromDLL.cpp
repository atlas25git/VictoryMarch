//Function to make binary tree from linked list.
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
        TreeNode* l=NULL,*r=NULL;
        l= new TreeNode(head->data);
        q.push(l);
        head=head->next;
        //head=next(head,1);
        if(head)
        {
            r=new TreeNode(head->data);
            q.push(r);
            head=head->next;
            //head=next(head,1);
        }
        
        t->left=l;
        t->right=r;
    }
}