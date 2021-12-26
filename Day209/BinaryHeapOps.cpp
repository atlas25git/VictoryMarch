//Function to extract minimum value in heap and then to store 
//next minimum value at first index.
int MinHeap::extractMin() 
{
    if(heap_size <= 0)return -1;
    if(heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
    int ele = harr[0];
    swap(harr[0],harr[heap_size - 1]);
    heap_size--;
    
    MinHeapify(0);
    return ele;
        
    }

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{   
    if(i<heap_size)
        decreaseKey(i,INT_MIN),
        extractMin();
}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k) 
{
    heap_size++;
    int i = heap_size-1;
    harr[i] = k;
    
    while(i>0 && harr[i] < harr[(i-1)/2])
    {
        // swap(harr[i],harr[(i-1)/2]);
        MinHeapify((i-1)/2);
        i = (i-1)/2;
    }
}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val) 
{
    harr[i] = new_val;
    while (i > 0 && harr[i] < harr[(i-1)/2]) {
        swap(harr[i], harr[(i-1)/2]);
        i = (i-1)/2;
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) 
{
    int l = 2*i+1;
    int r = 2*i+2;
    
    int smallest = i;
    if(l<heap_size && harr[l]<harr[smallest])smallest = l;
    if(r<heap_size && harr[r]<harr[smallest])smallest = r;
    
    if(i!=smallest)
    {
        swap(harr[i],harr[smallest]);
        MinHeapify(smallest);
    }
}