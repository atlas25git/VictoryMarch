class Solution{
  public:
  
    long long int sqrtR(long long int x,long long int l,long long int h,long long int& ans)
    {   if(h<l)return ans;
        long long int mid = l + (h-l)/2;

        if(mid*mid == x)return mid;
        else if(mid*mid<x){ans=mid,sqrtR(x,mid+1,h,ans);}
        else sqrtR(x,l,mid-1,ans);
    }
    
  
    long long int floorSqrt(long long int x) 
    {
       if(x==0 || x==1)return x;
       long long int h=x,l=1,ans;
       return sqrtR(x,l,h,ans);
        
    }
};

class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {    
        //base case
        if (x == 0 || x == 1) 
           return x;
     
        long long int start = 1, end = x, ans;   
        
        // binary search to find square root of a number
        while (start <= end) 
        {        
            long long mid = (start + end) / 2;
            
            // check if mid*mid == x
            if (mid*mid == x)
                return mid;
            
            // if mid*mid < x, then iterate on the upper half
            if (mid*mid < x) 
            {
                start = mid + 1;
                ans = mid;
            } 
            // else, iterate for the lower half
            else
                end = mid - 1;        
        }
        return ans;
    }
  

};