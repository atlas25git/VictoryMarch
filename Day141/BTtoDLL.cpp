class Solution
{   
    private:
    Node* head=NULL,*prev=NULL;
    
    public: 
    Node * bToDLL(Node *root)
    {
        if(!root)return root;
        dll(root);
        return head;
    }
    
    void dll(Node* rt)
    {
        if(!rt)return;
        dll(rt->left);
        if(!prev)head = rt;
        else{
            prev->right = rt;
            rt->left = prev;
        }
        prev = rt;
        dll(rt->right);
    }
};


class SolutionExplained
{
    public: 
    Node* prev=NULL;
    void bth(Node* root, Node*& head)
    {
        //base case
        if(!root)return;
        
        //We are asked to follow the inorder traversal
        //Step 1: write down the inorder traversal code
        
        bth(root->left,head);
        
        //Now this is the area where most work will 
        //happen
        //for the inorder traversal the left most leaf 
        //will be our head
        if(!prev)head=root;
        
        //now this else part will be executed for all other cases
        //here assume we've prev pointing to left child of the current root
        //all we gotta do is make their connections
        //  r
        // /
        //p
        else{
            root->left = prev;
            prev->right = root;
        }
        
        //Moving ahead our prev
        prev=root;
        
        bth(root->right,head);
        
    }
    
    
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        //Designing a helper fn.
        //since we're to use next and right pointers as  our fwd and bkd
        //we do not explicitly need to make a struct
        Node* head=NULL;
        bth(root,head);
        return head;
    }
};