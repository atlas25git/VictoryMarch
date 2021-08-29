int fill(Node* rt,int& mx,int& mn,int curr)
{
    if(!rt)return 0;
    fill(rt->left,mx,mn,curr-1);
    mn = min(mn,curr);
    fill(rt->right,mx,mn,curr+1);
    mx = max(mx,curr);
}

//Function to find the vertical width of a Binary Tree.
int verticalWidth(Node* root)
{
    if(!root)return 0;
    int mx=INT_MIN,mn=INT_MAX;
    fill(root,mx,mn,0);
    return mx + abs(mn) +1;
}


void lu(Node* root,int& max,int& min,int curr)
{
    if(!root)return;
    
    lu(root->left,max,min,curr-1);
    if(min>curr)min=curr;
    
    lu(root->right,max,min,curr+1);
    if(max<curr)max=curr;
}

//Function to find the vertical width of a Binary Tree.
int verticalWidth(Node* root)
{
    if(!root)return 0;
    int max=0,min=0;
    lu(root,max,min,0);
    return (abs(min) + max)+1;
}