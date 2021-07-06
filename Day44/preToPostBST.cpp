Node * constructTree ( int pre[], int size )
{
    if (canRepresentBST(pre, size) == false)
    {   cout << "NO";
        return NULL;
    }

    //creating a stack of capacity equal to size of array.
    Stack* stack = createStack( size );

    //first element of preorder traversal is always root of BST.
    Node* root = newNode( pre[0] );

    //pushing root into the stack.
    push( stack, root );

    int i;
    Node* temp;

    //iterating over rest of the array elements.
    for ( i = 1; i < size; ++i )
    {
        temp = NULL;

        //we keep on popping from stack while data at top of stack is less
        //than the current array element.
        while ( !isEmpty( stack ) && pre[i] > peek(stack)->data )
            temp = pop(stack);

        //we make this greater value as the right child and push it into stack.
        if ( temp != NULL)
        {
            temp->right = newNode( pre[i] );
            push( stack, temp->right );
        }

        //if current array element is less than data at top of stack, we make
        //it as the left child of the stack's top node and push it into stack.
        else
        {
            peek( stack )->left = newNode( pre[i] );
            push( stack, peek( stack )->left );
        }
    }
    return root;
     
}