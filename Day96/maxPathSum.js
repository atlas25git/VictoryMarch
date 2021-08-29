class Solution 
{   constructor()
    {
        this.res = -999999999;
    }
    //Function to return maximum path sum from any node in a tree.
    
    fill(root)
    {
        if(!root)return 0;
        
        let l = Math.max(0,this.fill(root.left));
        let r = Math.max(0,this.fill(root.right));
        
        this.res = Math.max(this.res, l + r +root.data);
        
        return root.data + Math.max(l,r);
        
        
    }
    
    findMaxSum(root)
    {
        this.fill(root);
        return this.res;
    }
}