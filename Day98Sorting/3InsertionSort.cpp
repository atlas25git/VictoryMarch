// O(n^2) worst case, array rev sorted
//O(n) Best case, already sorted
//In-place and stable
//used in practice for small arrays (Tim Sort)
// We maintain sorted and unsorted parts of the arrays.
// 0..i-1 || i....n-1
//sorted    unsorted

void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
        {
            int key = arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>key)
            {
                arr[j+1]=arr[j];
                j--;//marks for the element smaller than key's index
            }
            arr[j+1]=key;//places the key just in front of it
        }
}