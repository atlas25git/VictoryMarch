class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

        queue<Node*> q;
        q.push(root);
        int wdt=INT_MIN;
        while(!q.empty())
        {
            int ls = q.size();
            wdt = max(wdt,ls);
            while(ls--)
            {
                Node* t = q.front();
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                //ls--;
            }
            
        }
        return wdt;
    }
};