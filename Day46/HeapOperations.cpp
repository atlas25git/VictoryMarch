void MinHeap::insertKey(int k) 
{
    heap_size++;
    int i = heap_size - 1;
    //inserting the value at leaf node.
    harr[i] = k;

    while (i != 0 && harr[parent(i)] > harr[i])
    {
        //swapping values of ith index with its parent node
        //if value at parent node is greater.
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val)
{
    //storing new value at ith index.
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) 
    {
        //swapping values of ith index with its parent node
        //if value at parent node is greater.
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

//Function to extract minimum value in heap and then to store 
//next minimum value at first index.
int MinHeap::extractMin() 
{
    if (heap_size <= 0) return -1;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    //storing value of leaf node at first index.
    harr[0] = harr[heap_size - 1];
    harr[heap_size - 1] = 0;
    heap_size--;

    //calling heapify function for the first index.
    MinHeapify(0); 

    return root;
}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
    if (i < heap_size) 
    {
        //decreasing value at ith index to minimum integer value.
        decreaseKey(i, INT_MIN);
        //extracting the minimum value from heap.
        extractMin();
    }
}

//MinHeapify function is used to heapify ith index.
void MinHeap::MinHeapify(int i) 
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    
    //if left or right child is smaller than current element, 
    //we store its position.
    if (l < heap_size && harr[l] <harr[smallest]) 
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) 
        smallest = r;
        
    //if smallest is not equal to i, we swap the values at their position.
    if (smallest != i) 
    {
        swap(harr[i], harr[smallest]);
         //calling function recursively for the smallest index.
        MinHeapify(smallest); 
    }
}