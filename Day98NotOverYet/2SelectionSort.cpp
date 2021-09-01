//cmp based O(n^2) always
//Not stable
//less memory writes against
    //quick sort
    //merge sort
    //Insertion sort
//cycle sort is the most optimal in the suite.
//find the nth min element and place it in the right pos, and 
// replace the original index with infinite.
  
void selectSort(arr,n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_ind = i;
        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[min_ind])//finds the index of min element
                min_ind = j;
        swap(arr[min_ind],arr[i]);
    }
}