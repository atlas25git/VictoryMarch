class Solution{
public:
    int equalPartition(int n, int arr[])
    {   
        int ans;
        for(int i=0;i<n;i++)ans+=arr[i];
        if(ans&1)return 0;
        
        vector<vector<bool>> dp(2,vector<bool>(ans+1,0));
        
        for(int i=0;i<=ans;i++)dp[0][i]=false;
        dp[0][0] = true;
        dp[1][0]=true;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=ans;j++)
            {
                if(arr[i-1]>j)
                    dp[i%2][j] = dp[(i+1)%2][j];
                else
                    dp[i%2][j] = dp[(i+1)%2][j] || dp[(i+1)%2][j-arr[i-1]];
            }
        }
        
        
        return dp[n%2][ans/2];
    }
};