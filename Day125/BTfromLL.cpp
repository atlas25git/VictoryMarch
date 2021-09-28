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

void convert1(Node *head, TreeNode *&root) 
{
    //queue to store the parent nodes.
    queue<TreeNode *> q;
    
    //base case.
    if (head == NULL) 
    {
        root = NULL;
        return;
    }
    
    //the first node is always the root node so we add it to the queue.
    root = new TreeNode(head->data);
    q.push(root);
    
    head = head->next;
    
    //using a loop until we reach end of the linked list.
    while (head) 
    {
        //storing the front node from queue and removing it from queue.
        TreeNode *k = q.front();
        q.pop();
        
        //taking next two nodes from the linked list and adding them as 
        //children of the current parent node. Pushing them into the queue
        //so that they will be parents to the future nodes.
        TreeNode *leftT = NULL;
        TreeNode *rightT = NULL;
        leftT = new TreeNode(head->data);

        q.push(leftT);
        head = head->next;
        if (head) 
        {
            rightT = new TreeNode(head->data);
            q.push(rightT);
            head = head->next;
        }
        
        //assigning left and right children of parent node.
        k->left = leftT;
        k->right = rightT;
    }
}

//Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    
    if(!head){root=NULL;return;}
    queue<TreeNode*> q;
    TreeNode* t = new TreeNode(head->data);
    head = head->next;
    q.push(t);
    
    while(head)
    {
        TreeNode* cr = q.front();
        q.pop();
        TreeNode *l=NULL,*r=NULL;
        
        l = new TreeNode(head->data);
        q.push(l);
        head = head->next;
        
        if(head)
        {
            r = new TreeNode(head->data);
            q.push(r);
            head = head->next;
        }
        
        cr -> left = l;
        cr->right = r;
    }
    
    return;
    }