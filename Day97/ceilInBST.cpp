int findCeil(Node* root, int input) 
{ 
    if (root == NULL) 
        return -1; 
    Node* res = NULL;
    while(root)
    {
        if(root->data == input)
            return root->data;
            
        else if(root->data < input )
            root = root->right;
        else if(root->data > input)
        {
            res = root;
            root=root->left;
        }
    }
  
  
    return !res?-1:res->data;
} 