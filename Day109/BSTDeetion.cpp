Node *minValueNode(Node *nod)
{   
    if(!nod->left)return nod;
    return minValueNode(nod->left);
}

Node* deleteNode(Node* root, int key)
{
    
    // base case
    if (root == NULL)
    return root;
    
    //if given value is less than data at current node, we call function 
    //recursively to delete in left subtree.
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    
    //else if given value is more than data at current node, we call function 
    //recursively to delete in right subtree.
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    
    //else we need to delete the current node. 
    else
    {
        //if node is with only one child or no child. 
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        
        //if node has two children, getting the inorder successor  
        //(smallest in the right subtree). 
        struct Node* temp = minValueNode(root->right);
        
        //copying the inorder successor's data to this node.
        root->data = temp->data;
        
        //deleting the inorder successor.
        root->right = deleteNode(root->right, temp->data);
    } 
    return root;
}