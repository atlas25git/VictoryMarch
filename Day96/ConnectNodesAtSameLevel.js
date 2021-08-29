class Solution 
{
    //Function to connect nodes at same level.
    connect(p)
    {
        //here our approach is to do a level order traversal while maintaining
        //particular level's end,
        //while inserting nodes at a particulr level we also keep count of the ones int
        //the corressponding level
        //for first it'll be root only
        //and a prev for storing the prev node in a level.
        //now if the prev node is not set then it means we are at the level start
        //hence we'll put it equal to our curr.
        //in any other case we put our prev to curr root.
        
        let q=[];
        q.push(p);
        let lvlend = p,
            prev=null,
            curr=null,
            nxtLvlEnd = null;
        while(q.length)
        {
            curr = q[0];
            q.shift();
            if(curr.left)
            {
                q.push(curr.left);
                nxtLvlEnd = curr.left;
            }
            if(curr.right)
            {
                q.push(curr.right);
                nxtLvlEnd = curr.right;
            }
            if(prev)//first member of every level
                prev.nextRight = curr;
            prev = curr;
            
            if(curr == lvlend)
            {
                curr.nextRight = null;
                lvlend = nxtLvlEnd;
                prev=null;
            }
        }
    }
}