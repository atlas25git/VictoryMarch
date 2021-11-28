class Solution{
    public:
    // Function to count number of Ones
    // arr: input array 
    // N: size of input array
    int countOnes(int arr[], int N)
    {
        
        int start = 0,end = N-1;
        while(start<=end)
        {
            int m = start+(end-start)/1;
            if(m<N && arr[m+1] == 1)start = m+1;
            else if(m>0 && arr[m-1]==0)end = m-1;
            else if(m==N-1 && arr[m] == 1) return m+1;
            else return m;
        }
        return 0;
    }
};
