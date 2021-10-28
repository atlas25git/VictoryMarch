void fill(Node* root,vector<int>& res)
{
    if(!root)return;
    fill(root->left,res);
    fill(root->right,res);
    res.push_back(root->data);
}

//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
{
    vector<int> res;
    fill(root,res);
    return res;
}