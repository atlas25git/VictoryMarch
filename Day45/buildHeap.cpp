//we start from the bottom most and right most internal node given by the parent of 
//the last element, thus we cal minHEapify for all other roots in the path till root.

void buildHeap()
{
    for(int i=(size-2)/2;i>=0;i--)
        minHeapify(i);
}