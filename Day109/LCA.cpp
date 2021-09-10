//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
   if(!root)return root;
   if(root->data == n1 ||  root->data ==n2)return root;
   Node* l = LCA(root->left,n1,n2);
   Node* r = LCA(root->right,n1,n2);
   if(l&&r)return root;
   return l?l:r;
   
}

