Node *newNode(int data);

int search(int arr[], int strt, int end, int value);

//Function to construct binary tree from postorder and inorder traversals. 
Node *buildTreeUtil(int in[], int post[], int inStrt, int inEnd, int *index) 
{
    //base case
    if (inStrt > inEnd) return NULL;

    //picking current node from postorder traversal using postIndex
    //and decrementing postIndex.
    Node *tNode = new Node(post[*index]);
    (*index)--;

    //if this node has no children then we return the node.
    if (inStrt == inEnd) 
    return tNode;

    //else we find the index of this node in inorder traversal.
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    //using index in inorder traversal, we construct right and left subtrees
    //by calling the function buildTreeUtil recursively.
    tNode->right = buildTreeUtil(in, post, inIndex + 1, inEnd, index);
    tNode->left = buildTreeUtil(in, post, inStrt, inIndex - 1, index);

    return tNode;
}

//Function to find index of a value in array.
int search(int arr[], int strt, int end, int value) 
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value) return i;
    }
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{
    int index = n - 1;
    return buildTreeUtil(in, post, 0, n - 1, &index);
}
