#define ll long long
class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        ll sum=0;
        for(int i=0;i<N;i++)sum+=A[i];
        ll ans=INT_MAX,s=0,e=sum;
        while(s<=e)
        {
            ll  m = s + (e-s)/2;
            if(isP(A,N,M,m))
            {
                ans = min(ans,m);
                e=m-1;
            }
            else s=m+1;
        }
        return ans;
    }
    
    bool isP(int arr[],int n,int st,int mp)
    {
        int str = 1;
        int cs = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mp)return false;
            if(arr[i] + cs <= mp)
            {
                cs+=arr[i];
            }
            else
            {
                str+=1;
                if(str>st)return false;
                cs = arr[i];
            }
        }
        return true;
    }
};