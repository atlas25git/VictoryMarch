//swap the node root with the last in array
//now call heapify for arr[0];

int extractMin()
{
    if(!size)return INT_MAX;
    if(size==1)
    {
        size--;
        return arr[0];
    }
    swap(arr[0],arr[size-1]);//size is a one based index count
    size--;
    minHeapify(0);
    //sinxe the size has been reduced thus the last element wont be
    //altered in anyway
    return arr[size];//size has already been reduced.
}