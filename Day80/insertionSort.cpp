// { Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends

class Solution
{
    public:
    void insert(int arr[], int i)
    {
        //code here
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort1(int arr[], int n)
    {   
        for(int i=1;i<n;i++)
        {
            int key = arr[i];
            int j=i-1;
            while(j>=0 && key<arr[j])
            {
                arr[j+1]=arr[j];
                j--;
            }
            //if while loop doesn't run that case is negated by the 
            //logic that the key is just inserted at the position at which intially
            //it was.
            arr[j+1]=key;
        }
    }
    
    void insertionSort(int arr[],int n)
    {
        for(int i=1;i<n;i++)
        {
        int key = arr[i];
        int window = i-1;
        while(window>-1 && key<arr[window])
        {   
            arr[window+1] = arr[window];
            window--;
        }
        arr[window+1] = key;
        
        }
    }
};

// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends