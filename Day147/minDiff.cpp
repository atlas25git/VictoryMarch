class Solution{
    public:
    //Function to find minimum difference between any pair of elements in an array.
    int MinimumDifference(int arr[], int n)
    {
        sort(arr,arr+n);
        int min1=INT_MAX;
        for(int i=1;i<n;i++)
            min1=min(arr[i]-arr[i-1],min1);
        return min1;
    }
};