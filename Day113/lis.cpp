int longestSubsequenceR(int n, int a[])
    {   
        //our goal is to store at i, min no with which an inc. subsequence
        //of len i could end, and thus for subsequen arr elements the len 
        //will be increasing as greater elements are discovered.
        vector<int> lis(n,0);
        int len=0;
        lis[0]=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]>lis[len])lis[++len]=a[i];
            else
            {
                lis[lower_bound(lis.begin(),lis.begin()+len,a[i])-lis.begin()] = a[i];
            }
        }
        return len+1;
    }