#define ll long long 
class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        ll sum = accumulate(A,A+N,0);
        ll s=0,e=sum;
        int ans = INT_MAX;
        
        while(s<=e)
        {
            int m = s + (e-s)/2;
            if(isP(A,N,M,m))
            {
                ans = min(ans,m);
                e=m-1;
            }
            else s=m+1; 
        }
        return ans;
    }
    
    bool isP(int arr[],int N,int M,int m)
    {
        int str = 1;
        int cs = 0;
        
        for(int i=0;i<N;i++)
        {
            if(arr[i]>m)return false;
            if(arr[i] + cs<=m)cs+=arr[i];
            else
                str+=1,
                cs=arr[i];
        }
        
        return !(str>M);
    }
};
