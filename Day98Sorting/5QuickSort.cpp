//Partition
    //1) Stable:
        //Naive
    //2) Not Stable:
        //Lomuto
        //Hoare (fastest)


//Naive:
// O(n) space and time using an auxilary array
// Requires 4 traversals of the array.

//Lomuto Partition: Pivot Last element
//Places one element at it's actual position acc to sorting
//O(n) time with just one traversal.
//Constant space.

int lPartition(int arr[],int l,int h)
{
    int pivot = arr[h];
    int i = l-1;
    for(int j = l;j<h;j++)
    {
        if(arr[j]<pivot)
        {   //at i ends the window of smaller elements.
            //i+1 is swapped with the found prospective element.
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return (i+1);
}

//Hoare's Partition: Pivot arr[0] = low
//Not stable
//Takes less cmp than lomuto and works much better
//O(n) time, 1 traveral.
//Constant Space O(1)
//i = l-1, j=h+1;
 
 int partitionH(int arr[],int l, int h)
 {
     int pivot = arr[l];
     int i=l-1,j=h+1;
     while(1)
     {
         do{
             i++
         }while(arr[i]<pivot)
         do{
             j--;
         }while(arr[j]>pivot)
         if(i>=j)return j;
         swap(arr[i],arr[j]);
     }
 }

//  Quick Sort: stable if using Naive partition
// Tail call elimination happens here.
// Pivot is chosen randomly to avert adversary analysis.
// theta(n) worst case storage complexity as on recursion call stack.
//Divide and conquer algorithm
//Worst case time O(n^2)
//Advantages:
    //a) In Place//though not if counting recusrive call stack
    //b) Cache Friendly
    //c) Average case is O(nlogn)
    //d) Tail Recursive

//Lomuto Used:
void qSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int p = partition(arr,l,h);
        qSort(arr,l,p-1);
        qSort(arr,p+1,h);
    }

}

//Hoare's Partition:
 void qSort(int arr[],int l,int h)
 {
     if(l<h)
     {
         int p = partition(arr,l,h);
         qSort(arr,l,p);
         qSort(arr,p+1,h);
     }
 }

//tail call eliminated:

  void qSort(int arr[],int l,int h)
 {  
     Begin:
     if(l<h)
     {
         int p = partition(arr,l,h);
         qSort(arr,l,p);
         l = p+1;
         goto Begin;
     }
 }

