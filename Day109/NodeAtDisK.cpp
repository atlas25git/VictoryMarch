    //coz a particular ht would represent many nodes in the level
    //and for a particular subtree the pl value used for call will be same
    //hence there, it'd be called on same pL hence no false hit, but when 
    //adj nodes of same level with diff subtrees are called we need to mark the pL as
    //false as this is to be used again.

void fill(Node* root,int k, int&c, int pL,vector<bool>& vis)
{
    if(!root)return;
    
    vis[pL] = false;
    pL++;
    
    if(!root->right && !root->left && pL-k-1>=0 && !vis[pL-k-1])
    {
        c+=1;
        vis[pL-k-1] = true;
        return;
    }
    
    fill(root->left,k,c,pL,vis);
    fill(root->right,k,c,pL,vis);
}

//Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node* root, int k)
{
	vector<bool> vis(MAX_HEIGHT,false);
	int c=0;
	fill(root,k,c,0,vis);
	return c;
}
