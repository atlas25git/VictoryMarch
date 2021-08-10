class Solution{
    public:
    
    // The function should do the stated modifications in the given array arr[]
    // Do not return anything.
    
    // arr[]: Input Array
    // N: Size of the Array arr[]
    //Function to segregate 0s, 1s and 2s in sorted increasing order.
    void segragate012(int arr[], int N)
    {
        int w1 = 0,w2 = N-1;
        int itr = 0;
        while(itr<=w2)
        {
            if(arr[itr] == 0)
            {
                swap(arr[itr++],arr[w1++]);
            }
            else if(arr[itr] == 2)
                swap(arr[itr],arr[w2--]);
            else itr++;
        }
    }
};
