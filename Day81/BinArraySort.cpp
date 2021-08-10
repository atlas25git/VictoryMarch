void binSort(int A[], int N)
    {
       //Your code here
       
       /**************
        * No need to print the array
        * ************/
        
        int start=0,end=N-1;
        if(!N || N==1)return;
        
        while(true)
        {
            while(A[start]==0)start++;
            while(A[end]==1)end--;
            if(start>end)return;
            swap(A[start++],A[end--]);
        }
        
    }

class Solution{
  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
    void binSort(int arr[], int N)
    {
       //Your code here
       
       /**************
        * No need to print the array
        * ************/
        // int nsz = -1;
        // for(int i=0;i<N;i++)
        // {
        //     if(arr[i]==0)
        //     {
        //         nsz++;
        //         swap(arr[nsz],arr[i]);
        //     }
        // }
        
        int i=-1,j=N;
        
        while(true)
        {
            do{
                i++;
            }while(arr[i]==0);
            do{
                j--;
            }while(arr[j]==1);
            if(j<i)return;
            swap(arr[i],arr[j]);
        }
        
    }
};