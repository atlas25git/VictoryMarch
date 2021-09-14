class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int a[], int n)
    {
        int sum=0;
        for(int i=0;i<n;i++)sum+=a[i];
        if(sum%2)return false;;
        //dp[i][j] represents if a i elements make for the sum = j,
        //and hence we check if a sum of sum/2 is present hence equally partitionable
        bool dp[2][sum+1];
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
                {
                    if(!j)
                        dp[i%2][j]=true;
                    else if(!i)
                        dp[i%2][j]= false;
                        
                    else if(a[i-1]<=j)
                        dp[i%2][j] = dp[(i+1)%2][j] || dp[(i+1)%2][j-a[i-1]];
                    else
                        dp[i%2][j] = dp[(i+1)%2][j];
                }
                
        return dp[n%2][sum/2];
    }
};