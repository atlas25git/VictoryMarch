void check(Node* root,unordered_set<int>& s,int sum,int& mark)
{
        if(!root)return;
        //inorder traversal
        check(root->left,s,sum,mark);
        
        if(s.find(sum - root->data)!=s.end())
            {mark++;return;}
        else s.insert(root->data);
       
        check(root->right,s,sum,mark);
}

//Function to check if any pair exists in BST whose sum is equal to given value.
bool findPair(Node* root, int X) 
{
    //simp approach
    //maintain a set and look up for the pair
    //to be present just like in arrays using inorder
    //traversal
    unordered_set<int> s;
    int mark=0;
    check(root,s,X,mark);
    if(mark)
        return true;
    else 
        return false;
}