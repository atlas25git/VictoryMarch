class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       int start = 0,end= n-1;
       if(arr[0]>arr[1])return 0;
       if(arr[n-1]>arr[n-2])return n-1;
       while(start<=end)
       {
           int m = start + (end-start)/2;
           if(arr[m]>=arr[m-1] && arr[m]>=arr[m+1])return m;
           else if(arr[m]<arr[m-1])end = m-1;
           else if(arr[m]<arr[m+1])start = m+1;
       }
       return -1;
    }
};