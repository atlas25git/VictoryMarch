int minPages(int arr[],int n,int k)
{
    if(k==1)return sum(arr,0,n);
    if(n=1)return arr[0];

    int res = INT_MAX;
    for(int i=1;i<n;i++)
    {
        res = min(res,
                    //computes max value of pages that a student will read
                    //for the ith cut
                    max(minPages(arr,i,k-1),
                        sum(arr,i,n-1)));
    }

    return res;
}

int sum(int arr[],int b,int e)
{
    int s=0;
    for(int i=b;i<=e;i++)
        s+=arr[i];
    return s;
}