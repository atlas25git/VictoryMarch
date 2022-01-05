class Solution
{
  public:
  
    Node* prev=NULL;
    void bth(Node* root,Node*& head,int& count)
    {
        
        if(root==NULL)return;
        
        bth(root->left,head,count);
        
        if(!prev)head=root;
        else{
            //count++;
            root->left = prev;
            prev->right = root;
        }
        prev=root;
        
        bth(root->right,head,count);
    }
  
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {   
        if(!root)return NULL;
        Node* head=NULL;
        int count=1;
        bth(root,head,count);
        Node *temp = head;
        while(temp->right)
        {
            temp=temp->right;
        }
        //Node* temp1 = next(head,3);
        //cout<<temp1->data<<" Count\n";
        head->left=temp;
        temp->right=head;
        
        //Node* temp = next(head,count);
        // temp->right=head;
        // head->left=temp;
        
        return head;
    }
};