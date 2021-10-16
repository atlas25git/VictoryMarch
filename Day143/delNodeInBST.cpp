Node *minValueNode(Node *nod)
{   
    if(!nod->left)return nod;
    return minValueNode(nod->left);
}

Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    
    else if(root->data == key)
    {
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
        struct Node* temp = minValueNode(root->right);
        
        //copying the inorder successor's data to this node.
        root->data = temp->data;
        
        //deleting the inorder successor.
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}