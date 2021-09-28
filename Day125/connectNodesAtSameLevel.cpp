class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
        //We are basically maintianing the end node of a level
        //and while inserting in the queue, we also maintain it's end.
        //we mark the q.front as our curr and also maintain a prev,
        //if we haven't yet reached the level end we store temp in prev.
        //and in every iteration of the loop our curr progresses by q.front();
        if(!root)return;
        queue<Node*> q({root});
        Node *curr=NULL,*lvlEnd=root,*nxtLvlEnd=NULL,*prev=NULL;
        
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            if(curr->left)
            {
                q.push(curr->left);
                nxtLvlEnd = curr->left;
            }
            if(curr->right)
            {
                q.push(curr->right);
                nxtLvlEnd = curr->right;
            }
            
            if(prev)prev->nextRight = curr;
            prev = curr;
            
            if(curr == lvlEnd)
            {
                curr->nextRight = NULL;
                lvlEnd = nxtLvlEnd;
                nxtLvlEnd = NULL;
                prev = NULL;
            }
        }
        
    }    
      
};

