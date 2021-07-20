int isSumProperty(Node *node)
{
 // Add your code here
    int ld=0,rd=0;
    if(!node || (!node->left && !node->right))return 1;//one will corresspond to the &&
    else{
        if(node->left)
            ld = node->left->data;
        if(node->right)
            rd = node->right->data;
        if(
            (node->data == (ld + rd))
                && isSumProperty(node->left)
                    && isSumProperty(node->right)
        
        )return 1;
        else return 0;
    }
 
}

