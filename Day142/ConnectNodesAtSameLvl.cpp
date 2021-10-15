   void connect1(Node *root)
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


     void connect(Node *root){
        queue<Node*> q;
        q.push(root);
        Node* prev=NULL,*curr=NULL,*lE=NULL,*nlE=NULL;
        lE = root;
        
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            
            if(curr->left)
                q.push(curr->left),
                nlE = curr->left;
            
            if(curr->right)
                q.push(curr->right),
                nlE = curr->right;
                
            if(prev)prev->nextRight = curr;
            
            if(lE == curr)
            {
                curr->nextRight = NULL;
                lE = nlE;
                nlE = NULL;
                prev = NULL;
            }
            else
            prev = curr;
        }
    }