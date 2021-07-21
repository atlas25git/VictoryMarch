class Solution {
    
    constructor(){
        this.root = null;
    }
    
    //Function to create nodes.
    createNode(parent, i, created)
    {
        //base case if this node is already created.
        if (created[i] !== null)
            return;
            
        //creating a new node and setting created[i].
        created[i] = new Node(i);
        
        //if 'i' is root, changing root pointer.
        if (parent[i] == -1)
        {
            this.root = created[i];
            return;
        }
        
        //if parent is not created then we create parent first.
        if (created[parent[i]] === null)
            this.createNode(parent, parent[i], created);
        
        //finding parent pointer. 
        let p = created[parent[i]];
        
        //if this is first child of parent, we store it as left child.
        if (p.left === null)
            p.left = created[i];
        //else we store it as right child.
        else 
            p.right = created[i];
    }
    
    //Function to construct binary tree from parent array.
    createTree(parent, n)
    {
        //creating an array created[] to keep track of created nodes, 
        //initializing all entries as NULL.
        let created = [];
        for (let i=0; i<n; i++)
            created.push(null);
            
        for (let i=0; i<n; i++)
            this.createNode(parent, i, created);
    
        //returning root of created tree.
        return this.root;
    }
}