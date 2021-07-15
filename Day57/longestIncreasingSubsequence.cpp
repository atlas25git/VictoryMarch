class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    // int longestSubsequence(int n, int a[])
    // {
    //   int lis[n]={0};lis[0]=1;
    //max lken of lis ending with arr[i];
    //   for(int i=1;i<n;i++)
    //   {
    //       lis[i]=1;
    //       for(int j=0;j<i;j++)
    //       if(a[j]<a[i])
    //       lis[i]=max(lis[i],lis[j]+1);
    //   }
       
    //   int res = lis[0];
    //   for(int i=1;i<n;i++)res=max(res,lis[i]);
    //   return res;
    // }
    
    // int ceilIdx(int tail[], int l, int r, int key) 
    //     { 
    //         while (r > l) {         
    //             int m = l + (r - l) / 2; 
    //             if (tail[m] >= key) 
    //                 r = m; 
    //             else
    //                 l = m+1; 
    //         } 
      
    //         return r; 
    //     } 
  
    int longestSubsequence(int n,int arr[]) 
    { 
     
  
        int tail[n]; 
        int len =1; 
  
        tail[0] = arr[0]; 
        //the idea is to fill out the tail array for every index i representing the len,
        //and ending at the smallest possible array element.
        for (int i = 1; i < n; i++) {
            
            if(arr[i] > tail[len - 1])//len initialized with 1
            {
                tail[len] = arr[i];
                len++;
            }
            else{
                int c =upper_bound(tail,tail+len-1,arr[i])-tail;
                tail[c] = arr[i];
            }
        } 
        
        return len; 
    } 
    
                //int x =upper_bound(tail,tail+len-1,arr[i])-tail;
                //cout<<"c: "<<c<<"ub: "<<x<<endl;
    
    
};


//sol latest
class Solution
{
    public:
    //binary search function finds the position of the first integer
    //in arr[] which is greater than or equal to 'value'.
    int binarySearch(int arr[], int l, int h, int value)
    {
        //if new value is greater than all array values,
        //then it is placed at the end.
        if(value>arr[h]) 
        return h+1;
       
        //binary search algorithm.
        while(h>l)
        {
            int middle = (h+l)/2;
            
            if(arr[middle] == value)
            return middle;
            
            if(arr[middle] > value)
            h = middle;
            
            else 
            l = middle + 1;
        }
        
        return h;
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        //tail[i] holds the min possible last value in a subsequence of length i+1.
        int tail[n];
        tail[0] = a[0];
        
         //the position of last filled index in tail[].
        int lastIndex = 0;
        
        for(int i=1; i<n; i++)
        {
            //getting the furthest possible index for a[i].
            int index = binarySearch( tail, 0, lastIndex, a[i] );
            //l[i] -> holds the min possible value for lis of length i+1;
            tail[index] = a[i];
            //updating lastIndex.
            lastIndex = max( lastIndex, index );
        }
        //returning the result.
        return lastIndex + 1;
    }
};
