int c;
vector<int> ans;
void fill(Node* root,int pl,int k,vector<pair<bool,int>>& vis)
{
    if(!root)return;
    vis[pl].first = false;
    vis[pl].second = root->data;
    pl++;
    //We're considering pl-k>=0 and not blatantly ==0 or >0
    //because our pL could be large and in the process we can thus 
    //encounter such cases.
    //if we used original k then we may use dis>0
    if(!root->left && !root->right && pl-k>0 && !vis[pl-k-1].first)
    {
        c++;
        vis[pl-k-1].first = true;
        ans.push_back(vis[pl-k-1].second);
        return;
    }
    fill(root->left,pl,k,vis);
    fill(root->right,pl,k,vis);
}



//Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node* root, int k)
{
	//the idea here is to maintain a mark of all the nodes
	//which are ancestors of a leaf while traversing to it.
	//if the k is valid, i.e., doesn't exceed the total height of
	//the tree we count it and mark true;
	//now for other subsequent calls that will be made for other half of the tree
	//we mark the boolean array marking visited nodes as false as this
	//is ensured that thenode that has already been printed won't be printed again 
	//as we are totally delineating the search space.
	//and for the nodes which stay common, lie beyond concievable pL where it diverges,
	//as pL in called
	//sub calls on children would be beyond that of common node's level.
	   
	 vector<pair<bool,int>> vis(1e5);
	 c=0;
	 ans.clear();
	 //the pl-k-1 logic was to ascertain that the current ancestor node is k distance
	 //strictly above the given leaf node.
	 fill(root,0,k,vis);
// 	 cout<<" Nodes : "<<"\n";
// 	 for(auto x: ans)
// 	 {
// 	     cout<<x<<" ";
// 	 }
// 	 cout<<endl;
	 return c;
	
}