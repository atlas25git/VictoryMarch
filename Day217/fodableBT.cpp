bool isf(Node* r1, Node* r2)
{
    if(!r1 && !r2)return true;
    if(!r1 || !r2) return false;
    
    return isf(r1->left,r2->right) && isf(r1->right,r2->left); 
}

//Function to check whether a binary tree is foldable or not.
bool IsFoldable(Node* root)
{
    if(!root)return true;
    return isf(root->left,root->right);
}