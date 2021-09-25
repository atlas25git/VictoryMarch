class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int> res;
        stack<Node*>s1,s2;
        
        while(1)
        {
            if(root1){s1.push(root1);root1 = root1->left;}
            else if(root2){s2.push(root2);root2=root2->left;}
            else if(!s1.empty() && !s2.empty())
            {
                root1 = s1.top();
                root2 = s2.top();
                
                if(root1->data == root2->data)
                {
                    res.push_back(root2->data);
                    s1.pop(),s2.pop();
                    root1 = root1->right;
                    root2 = root2->right;
                }
                else if(root1->data > root2->data)
                {
                    s2.pop();
                    root2 = root2->right;
                    root1 = NULL;
                }
                else if(root1->data < root2->data)
                {
                    s1.pop();
                    root1 = root1->right;
                    root2 = NULL;
                }
            }
            else break;
        }
        return res;
    }
};