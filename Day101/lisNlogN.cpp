int longestSubsequence(int n, int a[])
    {
        vector<int> lis(n,0);
        int len=0;
        lis[0]=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]>lis[len])lis[++len]=a[i];
            else
            {
                lis[upper_bound(lis.begin(),lis.begin()+len,a[i])-lis.begin()] = a[i];
            }
        }
        return len+1;
    }