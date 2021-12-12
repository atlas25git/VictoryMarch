class Solution{
  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
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
};