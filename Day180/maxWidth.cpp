class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        queue<Node*> q;
        q.push(root);
        int ht=INT_MIN;
        while(!q.empty())
        {
            int ls = q.size();
            ht = max(ht,ls);
            while(ls--)
            {
                Node* t = q.front();
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            
        }
        return ht;
    }
};