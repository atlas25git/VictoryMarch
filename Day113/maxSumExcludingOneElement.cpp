class Solution
{
    public:
    //Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarray(int A[], int n)
    {
        vector<int> f(n,0),b(n,0);
        int cm=0,msf=0;
        
        for(int i=0;i<n;i++)
                cm = max(A[i],cm+A[i]),
                msf = max(msf,cm),
                f[i] = cm;
        
        cm=0,msf=0;
        for(int i=n-1;i>-1;i--)
            cm = max(A[i],cm+A[i]),
            msf = max(msf,cm),
            b[i] = cm;
        int ans = msf;
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
                {ans = max(ans,b[1]);continue;}
            if(i==n-1)
                {ans = max(ans,f[n-2]);continue;}
            ans = max(ans,f[i-1] + b[i+1]);
        }
        if(ans<=0)return *max_element(A,A+n);
        return ans;
    }
};