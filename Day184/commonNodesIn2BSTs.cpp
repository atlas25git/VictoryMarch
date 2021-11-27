class Solution
{   set<int> s;
    vector<int> v;
    void fill_s(Node* root)
    {
        if(!root)return;
        fill_s(root->left);
        s.insert(root->data);
        // cout<<root->data<<": ";
        fill_s(root->right);
        return;
    }
    
    void fill_v(Node* root)
    {
        if(!root)return;
        fill_v(root->left);
        if(s.count(root->data))
        {   
            v.push_back(root->data);
        
        }
            // cout<<root->data<<"_ ";
        fill_v(root->right);
        return;
    }
    public:
    
    vector <int> findCommon1(Node *root1, Node *root2)
    {
        fill_s(root1);
        fill_v(root2);
        // for(auto x: s)cout<<x<<"_ ";
        return v;
    }
    
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        //approach:
        //maintain 2 stacks which would store the left most node
        //representing any subtree in question.
        //we'll fill up the stacks sequentially running a while loop
        //infinity times.
        //till the root nodes become null.
        //Now based on the relation in two subsequent stack tops, we'll do 
        //the proceedings.
        //if both are equal then we'll check for the right childs of the particular
        //node just popped
        //in other cases we'd fill our stacks with greater values for the smaller of
        //the two stack tops.
        
        //Iterative Inorder traversal
        stack<Node*> s1,s2;
        vector<int> res;
        
        while(1)
        {
            if(root1)
                s1.push(root1),
                root1 = root1->left;
            else if(root2)
                s2.push(root2),
                root2 = root2->left;
            else if(!s1.empty() && !s2.empty())
            {
                Node* x = s1.top();
                Node* y = s2.top();
                if(x->data == y->data)
                    res.push_back(x->data),
                    s1.pop(),s2.pop(),
                    root1 = x->right,root2=y->right;
                
                else if(x->data > y->data)
                {
                    //x can't have value lower than it, as it already is
                    //the level's left most
                    s2.pop();
                    root2 = y->right,
                    root1 = NULL;
                }
                else if(x->data < y->data)
                {
                    s1.pop();
                    root1 = x->right,
                    root2 = NULL;
                }
            }
            else break;
        }
        return res;
    }
};
