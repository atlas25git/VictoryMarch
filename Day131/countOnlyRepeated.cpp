class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<int, int> findRepeating(int *arr, int n){
        //we can use the property of consecutively increasing
        //elements and their accord with the no of elements
        
        if(arr[n-1] >= arr[0] + n)return {-1,-1};
        int s=0,e=n-1;
        int m=0;
        while(s<e)
        {
            m=s+(e-s)/2;
            if(arr[m]>=m+arr[0])
                s=m+1;
            else e=m;
        }
        
        return {arr[m],n-(arr[n-1]-arr[0])};
        
    }
};