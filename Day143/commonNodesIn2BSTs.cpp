class Solution
{
    public:
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
        
        stack<Node*> s1,s2;
        vector<int> res;
        while(1)
        {
            if(root1){s1.push(root1);root1=root1->left;}
            else if(root2){s2.push(root2);root2=root2->left;}
            else if(!s1.empty() && !s2.empty())
            {
                root1 = s1.top();
                root2 = s2.top();
                
                if(root1->data == root2->data)
                    res.push_back(root2->data),
                    s1.pop(),s2.pop(),
                    root1 = root1->right,root2=root2->right;
                
                else if(root1->data > root2->data)
                    s2.pop(),
                    root2 = root2->right,
                    root1 = NULL;
                else
                    s1.pop(),
                    root1 = root1->right,
                    root2 = NULL;
            }
            else break;
        }
        return res;
    }
};