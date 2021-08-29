void fill(Node* root,int k,int pl,vector<bool>& vis,int& c)
{
    if(!root)return;
    vis[pl]=false;//coz a particular ht would represent many nodes in the level
    pl++;
    if(!root->left && !root->right && pl-k-1>=0 && !vis[pl-k-1])
    {
        c+=1;
        vis[pl-k-1]=true;
        return;
    }
    fill(root->left,k,pl,vis,c);
    fill(root->right,k,pl,vis,c);
}

//Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node* root, int k)
{
	vector<bool> vis(MAX_HEIGHT,false);
	int c=0;
	fill(root,k,0,vis,c);
	return c;
}