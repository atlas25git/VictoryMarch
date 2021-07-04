//Function to find the maximum difference.
int maxDiffUtil(Node *t,int *res)
{
    //returning Maximum int value if node is null.
    if (t == NULL) 
        return INT_MAX; 
  
    //if there are no child nodes then we just return data at current node.
    if (t->left == NULL && t->right == NULL) 
        return t->data; 
  
    //recursively calling for left and right subtrees and 
    //choosing their minimum.
    int val = min(maxDiffUtil(t->left, res), 
                  maxDiffUtil(t->right, res)); 
  
    //updating res if (node value - min value from subtrees) is bigger than res.
    *res = max(*res, t->data - val); 
  
    //returning minimum value got so far.
    return min(val, t->data);
}

//Function to return the maximum difference between any node and its ancestor.
int maxDiff(Node *root)
{
    int res=INT_MIN;
    maxDiffUtil(root,&res);
    //returning the result.
    return res;
}