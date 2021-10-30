int fill(Node* root,int& diff)
{   //Through fn calls we discover the min element in 
    //the given tree and if it turns out that none of the children
    //are smaller then we simply denounce them all and proceed with root's
    //data
    if(!root)
        //returned max so that during the min filter, exisitng node gets selected
        //and in case of both being null, only the root node will get selected
        return INT_MAX;
    //redundant as returning Max would fix the job
    //if(!root->right && !root->left)return root->data;
    
    int l = fill(root->left,diff);
    int r = fill(root->right,diff);
    
    diff = max(diff,root->data - min(l,r));
    //zero in the case that diff might become negative
    //since if min(l,r) > root->data, the diff would become negative
    //hence ignoring this case
    return min(root->data,min(l,r));
}

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