int diff=0;
class Solution{
    public:
    
    // A[]: input array
    // N: size of array
    //Function to sort the array according to difference with given number.
    
    
    
    static bool cmp(int a,int b)
    {   
        a = abs(a-diff);
        b = abs(b-diff);
        return a<b;
    }
    
    void sortABS(int A[],int N, int k)
    {
       diff=k;
       stable_sort(A,A+N,cmp);
    }

};
