class Solution {
    //Function to find the height of a binary tree.
    height(node)
    {
        if(!node)return 0;
        
        return Math.max(1+this.height(node.left),1+this.height(node.right));
    }
}

class Solution {
    //Function to find the height of a binary tree.
    height(node)
    {
        if(!node)return 0;
        let q = [];
        q.push(node);
        let ht=0;
        while(q.length)
        {
            let ls = q.length;
            while(ls)
            {
                let t = q[0];
                q.shift();
                if(t.left)q.push(t.left);
                if(t.right)q.push(t.right);
                if(ls===1)ht++;
                ls--;
            }
        }
        return ht;
    }
}