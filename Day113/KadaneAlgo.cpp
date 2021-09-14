class Solution
{
    public:
    //Function to print the maximum contiguous subarray sum ending at each 
    //position in the array and return the overall maximum.
    long long maximumSum(int arr[], int n)
    {
       long long cs=0,msf=INT_MIN;
       for(int i=0;i<n;i++)
       {
           cs+=arr[i];
           msf = max(msf,cs);
           
           cout<<cs<<" ";
           if(cs<0)cs=0;
       }
       cout<<"\n";
       return msf;
    }
};