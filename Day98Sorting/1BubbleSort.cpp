//cmp based O(n^2)
//stable sorting algo
//inplace
//in every pass nth largest element is placed.
//swapping done when elements are out of order.

void bubbleSort(arr,n)
{
    bool swapped = 0;
    for(int i=0;i<n-1;i++) 
    {
        swapped = false;
       for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]),
                swapped = true;

        if(swapped == false)break;//sorted 
    }
}