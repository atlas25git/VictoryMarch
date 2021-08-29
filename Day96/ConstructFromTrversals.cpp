int idx=0;
int n1 =0;
Node* bt(int in[],int post[],int i,int j)
{   
    
    if(i>j)return NULL;
    Node* tnode = new Node(post[idx--]);    
    if(i==j)return tnode;
    int ind = find(in,in+n1,tnode->data) - in;
    tnode->right = bt(in,post,ind+1,j);
    tnode->left = bt(in,post,i,ind-1);
    return tnode;
}


Node *buildTree(int in[], int post[], int n) {
    idx = n-1;
    n1=n;
    return bt(in,post,0,n-1);
}


class Solution 
{   constructor(){
        this.index=0;
    }
    bT(ino,post,i,j)
    {   //This fn basically returns the built tree for this we take to markers
        //i and j denoting no of children for a given index's node.
        //if i==j we return the child,else we divide into sub Problems, and thus fill
        //node's right and left pointers and atlast return the node.
        if(i>j)return null;
        let tNode = new Node(post[this.index]);
        this.index--;
        if(i==j)return tNode;
        let inIndx = this.search(ino,i,j,tNode.data);
        //right before  the left becoz we are iterating from end of post order
        //hence right comes first than the left.
        tNode.right = this.bT(ino,post,inIndx+1,j);
        tNode.left = this.bT(ino,post,i,inIndx-1);   
        return tNode;
    }
    search(ino,i,j,x)
    {   for(let s = i;s<=j;s++)
            if(ino[s]==x)return s;
    }
    buildTree(ino, post, n)
    {   this.index = n-1;
            return this.bT(ino,post,0,n-1);
    }
}
