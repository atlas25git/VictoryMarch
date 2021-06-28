// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

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
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        //lomuto:
        // if(low<high)
        // {
        //     int p=partition(arr,low,high);
        //     quickSort(arr,low,p-1);
        //     quickSort(arr,p+1,high);
        // }
        
        //hoare
        if(low<high)
        {
            int p=partition(arr,low,high);
            quickSort(arr,low,p);
            quickSort(arr,p+1,high);
            
        }
    }
    
    public:
    int partition (int arr[], int l, int h)
    {
       //lomuto
    //   int p = arr[high];
    //   int nsz =low-1;
    //     for(int i=low;i<high;i++)
    //     {
    //         if(arr[i]<p)
    //         {
    //             nsz++;
    //             swap(arr[nsz],arr[i]);
    //         }
            
    //     }
    //     swap(arr[nsz+1],arr[high]);
    //     return nsz+1;
    
    //hoare
    
    // int p=arr[low];
    // int i=low,j=high;
    // while(true)
    // {
    //     while(arr[i]<=p)i++;
    //     while(arr[j]>p)j--;
    //     if(i>=j)return j;
        
    //     swap(arr[i],arr[j]);
    // }
    int pivot=arr[l];
    int i=l-1,j=h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)return j;
        swap(arr[i],arr[j]);
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
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends