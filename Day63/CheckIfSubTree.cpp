class Solution {
    vector<Node*> nodes;
public:
    bool isSubTree(Node* S, Node* T) {
        if (!S && !T) return true;
        if (!S || !T) return false;
        getDepth(S, getDepth(T, -1));
        for (Node* n: nodes)
            if (identical(n, T))
                return true;
        return false;
    }
    int getDepth(Node* r, int d) {
        if (!r)
            return -1;
        int depth = max(getDepth(r->left, d), getDepth(r->right, d)) + 1;
        // Check if depth equals required value
        // Require depth is -1 for tree t (only return the depth, no push)
        if (depth == d)
            nodes.push_back(r);
        return depth;
    }
    bool identical(Node* a, Node* b) {
        if (!a && !b) return true;
        if (!a || !b || a->data != b->data) return false;
        return identical(a->left, b->left) && identical(a->right, b->right);
    }
};

class D{
    constructor()
    {
        this.d = 0;
    }
}

class Solution {
    
    constructor()
    {
        this.con = [];
    }
    
    isSubTree(T, S)
    {
        //Basically our approach to problem here is as
        //we start with finding out the depth of subTree
        //now in the main tree we store the nodes which have
        //d depth deep depth and we store these in a vector.
        //and for each of them we check if the required node with depth
        //equal to subtree's is identical or not.
        
        if(!S && !T)return true;
        if(!S || !T)return false;
        let depS = this.getD(S,-1);
        //-1 as this ain't a valid depth and won't ever hit
        //the case where the nodes are stored in the vector.
        //as we only need to store nodes of the main Tree.
        this.getD(T,depS);
        // console.log(this.con);
        // console.log(S);
        
        this.con.forEach(x => {
            if(this.id(x,S)===true)
                return true;
            else return false;
        })
    }
    
    //this recursive fun builds up depth array bottom to down,
    //and while the rec callbacks end 1 is incremented.
    //at the moment when this is equal to the depth of subtree
    //we store this node for further testing.
    getD(r,d)
    {
        if(!r)return -1;
        let dep = Math.max(
                this.getD(r.left,d),
                this.getD(r.right,d)
                ) + 1;
        
        if(dep == d)
            this.con.push(r);
        return dep;
    }
    
    id(a,b)
    {   //console.log(this.con.length);
        if(a===null && b===null)return true;
        else if(a===null || b===null || (a.data !== b.data))return false;
        else return (this.id(a.left,b.left) 
                && this.id(a.right,b.right));
    }
    
}