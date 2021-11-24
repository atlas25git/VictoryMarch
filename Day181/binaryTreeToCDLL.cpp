class Solution {
public:
    TreeNode* prev,*head;
    /**
     * @param root: root of a tree
     * @return: head node of a doubly linked list
     */
    TreeNode * treeToDoublyList(TreeNode * root) {
        if(!root)return root;
        prev = NULL,head = NULL; 
        convert(root);
        make_circular(head);
        return head;
    }
    
    void convert(TreeNode* root)
    {
        if(!root)return;
        convert(root->left);
        if(!prev)head = root;
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        convert(root->right);
    }

    void make_circular(TreeNode* root)
    {
        TreeNode* curr = root;
        while(curr->right)
            curr = curr->right;
        curr->right = root;
        root->left = curr;
    }
};