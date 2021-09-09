int fill(Node* root,int X,int& c)
{
    if(!root)return 0;
    
    int ls = fill(root->left,X,c);
    int rs = fill(root->right,X,c);
    
    if(ls+rs+root->data == X)c++;
    
    return (ls+rs+root->data);
    
}

//Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumX(Node* root, int X)
{
	if(!root)return 0;
	int c=0;
	fill(root,X,c);
	return c;
}