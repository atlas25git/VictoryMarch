class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<int, int> findRepeating(int *arr, int n)
    {
        //if array has no repeating element, we return (-1,-1).
        if(n-(arr[n-1]-arr[0]) == 1){
            return {-1, -1};
        }
        
        int lo = 0, hi = n-1;
        int mid = 0;
        
        //using binary search to find the repeating element.
        while(lo < hi)
        {
            mid = (lo+hi)/2;
            
            //if arr[mid]=mid+arr[0], there is no repeating
            //number in [lo..mid].
            if(arr[mid] >= mid + arr[0])
            {
                //updating lo pointer.
                lo = mid+1;
            }
            //else there is repeating number in [lo..mid].
            else
            {
                //updating hi pointer.
                hi = mid;
            }
        }
        //returning the repeated element and its frequency.
        return {arr[mid], n-(arr[n-1]-arr[0])};
        
    }
};
class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<int, int> findRepeating(int *arr, int n){
        //code here
        
        if(n-(arr[n-1]-arr[0]) == 1)return {-1,-1};
        
        int s=0,e=n-1;
        //int i=INT_MAX,f=INT_MAX;
        int m=0;
        while(s<e)
        {
            m = s+(e-s)/2;
            if(arr[m] >= m + arr[0])
                s = m+1;
            else
                e = m;
        }
        
        return {arr[m],n-(arr[n-1]-arr[0])};
    }
};