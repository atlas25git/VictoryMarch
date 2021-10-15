int fill1(Node* root,int& diff)
{
    if(!root)return INT_MAX;
    
    int l = fill1(root->left,diff);
    int r = fill1(root->right,diff);
    
    int min_child = min(l,r);
    diff = max(diff,root->data - min_child);
    
    return min(root->data,min_child);
}

//Function to return the maximum difference between any node and its ancestor.
int maxDiff(Node* root)
{
    if(!root)return 0;
    int dif = INT_MIN;
    fill1(root,dif);
    return dif;
}