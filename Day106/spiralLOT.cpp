vector<int> findSpiral(Node *root)
{   
    vector<int> res;
    if(!root)return res;
    queue<Node*>q;
    q.push(root);
    bool flag = true;
    
    while(!q.empty())
    {   
        int ls = q.size();
        
       
        if(!flag)
        {
            while(ls)
            {
                Node* t=q.front();
                q.pop();
                res.push_back(t->data);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                ls--;
            }
            flag=true;
        }
        else{
            stack<int> s;
            
            while(ls)
                {
                Node* t=q.front();
                q.pop();
                s.push(t->data);
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                ls--;
            }
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        flag=false;
        }
    }
    return res;
}