vector<int> levelOrder(struct Node* node) {
    vector<int> ans;
    if(!node)return ans;
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty())
    {
        Node* fr = q.front();
        q.pop();
        ans.push_back(fr->data);
        if(fr->left)q.push(fr->left);
        if(fr->right)q.push(fr->right);        
    }
    return ans;
}