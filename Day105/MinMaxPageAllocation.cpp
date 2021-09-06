int minPages(int arr[],int n,int k)
{
    if(k==1)
        return sum(arr,0,n-1);
    if(n==1)
        return arr[0];
    int res = INT_MAX;
    for(int i=1;i<n;i++)
        //sum fn just computes the sum
        res = min(max(minPages(arr,i,k-1),sum(arr,i,n-1));

    return res;
}

//tabulation based sol:
//O(n^3*k) O(nk)space
//Keeping a pre computed sums array: )(n^2*k) , O(n^2) space
//binary search based solution : O(nlogSum)
int minPages(int arr[],int n,int k)
    int dp[k+1][n+1];
{   //dp[i][j] -> min pages for i people with j books 
    for(int i=1;i<=n;i++)
        dp[1][i] = sum(arr,0,i-1);
    for(int i=1;i<=k;i++)
        dp[i][1] = arr[0];
    for(int i=2;i<=k;i++)
        for(int j=2;j<=n;j++)
        {
            int res = INT_MAX;
            for(int p=1;p<j;p++)
                res = min(res,max(dp[i-1][p],sum(arr,p,j-1)));
            dp[i][j] = res;
        }
    return dp[k][n];
}