class Solution {
public:
    bool isSymmetricNR(TreeNode* root) {
        vector<TreeNode*> q;
        q.push_back(root);
        
        while(q.size())
        {
            int sz = q.size();
            // auto x = q[0];
            // cout<<sz<<endl;
            while(sz--)
            {
              auto x = q[0];
                if(x->val == INT_MAX)
                {
                    q.erase(q.begin());
                    continue;
                }
              q.erase(q.begin());
              if(x->left)q.push_back(x->left);
                else q.push_back(new TreeNode(INT_MAX));
              if(x->right)q.push_back(x->right); 
                else q.push_back(new TreeNode(INT_MAX));
            }
            
            int i=0,j=q.size()-1;
            
            while(i<j)
                if(q[i++]->val!=q[j--]->val)return false;
                // else cout<<q[i]->val<<" "<<q[j]->val<<endl;
                
            
        }
        
        return true;
    }
    
    bool isSymmetric(TreeNode* root)
    {
        if(!root)return true;
        return sym(root->left,root->right);
    }
    
    bool sym(TreeNode* r1,TreeNode* r2)
    {
        if(!r1 && !r2)return true;
        if(!r1 || !r2)return false;
        
        return (r1->val == r2->val && sym(r1->left,r2->right) && sym(r1->right,r2->left));
    }
};