levelOrder(node)
{
    //your code here
    let q = [];
    let res = [];
    q.push(node);
    while(q.length)
    {   
        let s=q.length;
        while(s--)
        {
        let t = q[0];
        q.shift();
        if(t)res.push(t.data);
        if(t.left)q.push(t.left);
        if(t.right)q.push(t.right);
        }
        
    }
    return res;
}