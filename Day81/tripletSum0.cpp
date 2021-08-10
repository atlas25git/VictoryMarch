class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr,arr+n);
        
        for(int i=0;i<n-2;i++)
        {
            int start = i+1;
            int end = n-1;
            
            while(start<end)
            {
            if(arr[i]+arr[start]+arr[end] == 0)return true;
            else if(arr[i]+arr[start]+arr[end] > 0)end--;
            else start++;
                
            }
            
        }
        return false;
        
    }
};

class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
            sort(arr,arr+n);
            for(int i=0;i<n-2;i++)
            {
                int x=arr[i];
                int l=i+1;
                int r=n-1;
                while(l<r)
                {
                    if(x+arr[l]+arr[r]==0)
                    {
                        return true;
                    }
                    else if(x+arr[l]+arr[r]<0)
                    l++;
                    else r--;
                }
            }
            return false;
    }
};