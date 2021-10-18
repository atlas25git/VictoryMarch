class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        int ans = INT_MAX;
        if(arr[low]<arr[high])
            return arr[low];
            
        while(low<=high)
        {
            int  m = low + (high-low)/2;
            
            if(m>low && arr[m]<arr[m-1])
            {
                ans = min(ans,arr[m]);
                break;
            }
            if(m<high && arr[m]>arr[m+1])
            {
                ans = min(ans,arr[m+1]);
                break;
            }            
            if(arr[m]>arr[high])
                low = m+1;
            else 
                high = m-1;
        }
        return ans;
    }
};