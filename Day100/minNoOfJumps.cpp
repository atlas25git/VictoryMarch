class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n){
        
        //base case
        if(n<=1)return 0;
        if(!arr[0])return -1;
        
        int mR = arr[0];
        int st = arr[0];
        int j=1;
        for(int i=1;i<n;i++)
        {
            //base case
            if(i==n-1)return j;
            
            mR = max(mR,arr[i]+i);
            //i and st are complementary to each other, hence
            //i denotes the step position max reachable from starting point.
            st--;
            if(!st)
            {
                j++;
                if(mR<=i)return -1;
                st = mR-i;
            }
        }
        return -1;
    }
};

//Recusive Solution to Jumps:

//1. Begin from last cell and find out all the cells through which we could have reached here.
//2. And recursively for these cells we find out min paradigm satisfying cells.

int minJumps(int arr[],int n)
{
    if(n==1)return 0;

    int res = INT_MAX;
    for(int i=0;i<=n-2;i++)
    {
        if(i+arr[i]>=n-1)
        {
            int subRes = minJumps(arr,i+1);
            if(sub_res!=INT_MAX)
                res = min(res,sub_res+1);
        }
    }
    return res;
}

//Dp based solution:

int minJumps(int arr,int n)
{
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++)
        dp[i]=INT_MAX;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
            {
                if(arr[j] + j >=i)
                {
                    if(dp[j]!=INT_MAX)
                        dp[i] = min(dp[i],dp[j]+1);
                }
            }
    }
    return dp[n-1];
}
