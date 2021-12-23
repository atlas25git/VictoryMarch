class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*> q;
        q.push(root);
        Node *currLvlEnd,*nxtLvlEnd,*prev=NULL;
        
        currLvlEnd = root;
        
        while(!q.empty())
        {
            Node* fr = q.front();
            q.pop();
            
            if(fr->left)
                {q.push(fr->left);
                nxtLvlEnd = fr->left;}
            if(fr->right)
                {q.push(fr->right);
                nxtLvlEnd = fr->right;}
        
            if(prev)prev->next = fr;
            
            if(fr == currLvlEnd)
            {
                prev = NULL;
                fr->next = NULL;
                currLvlEnd = nxtLvlEnd;
                nxtLvlEnd = NULL;
            }
            else
            prev = fr;
        }
        return root;
    }
};