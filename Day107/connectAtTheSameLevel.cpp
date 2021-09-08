class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
        //We arte basically maintianing the end node of a level
        //and while inserting in the queue, we also maintain it's end.
        //we mark the q.front as our curr and also maintain a prev,
        //if we haven't yet reached the level end we store temp in prev.
        //and in every iteration of the loop our curr progresses by q.front();
        if(!root)return;
        queue<Node*> q;
        q.push(root);
        Node* end=root,*lvlEnd=NULL,*curr=NULL,*prev=NULL;
        
        while(!q.empty())
        {
            curr =q.front();
            q.pop();
            
            if(curr->left)
            {
                q.push(curr->left);
                lvlEnd= curr->left;
            }
            if(curr->right)
            {
                q.push(curr->right);
                lvlEnd=curr->right;
            }
            if(prev)prev->nextRight = curr;
            prev=curr;
            
            if(curr==end)
            {
                curr->nextRight = NULL;
                end = lvlEnd;
                prev=NULL;
                
            }
            
        }
        
    }    
      
};