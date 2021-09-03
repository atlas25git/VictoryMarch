class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int ic = arr[0];
        int ec = 0;
        int ip = ic;
        int ep = ec;
        for(int i=1;i<n;i++)
        {
            ic = ep+arr[i];
            ec = max(ip,ep);
            
            ip = ic;
            ep = ec;
        }
        return max(ic,ec);
    }
};