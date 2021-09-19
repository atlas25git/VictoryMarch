class Solution{
    public:
        
    // arr[]: input array
    // n: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        
       //here what actually we do is that, we've to
       //find out max dis located arr elements such that
       //former is smaller than the latter
       //in the extra space solution, since we need to 
       //give max dis, we create 2 arrays, for the lMin
       //we store at index i the smallest value that is available
       //as only the left most and right most would help in
       //maximizing the distance possible
       
       if(n==0)return 0;
       
       int lmin[n],rmax[n];
       
       lmin[0] = arr[0];
       rmax[n-1]=arr[n-1];
       
       for(int i=1;i<n;i++)lmin[i]=min(arr[i],lmin[i-1]);
       for(int i=n-2;i>=0;i--)rmax[i]=max(arr[i],rmax[i+1]);
       
       int i=0,j=0,ans=-1;
       while(j<n && i<n)
       {
           if(lmin[i]<=rmax[j])
                ans=max(ans,j-i),j++;
           else i++;
       }
       
       return ans;
        
    }
};