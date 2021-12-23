 */
//When absolute diff is asked.
// int diff(Node* root,int mx,int mn)
// {
//     if(!root)return mx-mn;
//     mn = min(mn,root->data);
//     mx = max(mx,root->data);
//     return max(diff(root->left,mx,mn),diff(root->right,mx,mn));
// }

// Since the question requires us to compute the asked diff in a predefined order,
// and hence our algo will compute min element in a given subtree and store the diff
// of them from the root a that level throughout maintaing the max df as the ans.
int df;
int fill(Node* root)
{
    if(!root)return INT_MAX;
    int lmin = fill(root->left);
    int rmin = fill(root->right);
    
    df = max(df,root->data - min(lmin,rmin));
    return min({root->data,lmin,rmin});
}

int maxDiff(Node* root)
{
    df = INT_MIN;
    fill(root);
    return df;
}
