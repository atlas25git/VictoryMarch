#define ll long long
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{   ll m = 1e9+7;
        // Your code goes here
        vector<vector<ll>>dp(n+1,vector<ll>(sum+1,0));
        
        for(int i=1;i<n+1;i++)dp[i][0]=1;
        dp[0][0]=1;
        for(int i=1;i<=sum;i++)dp[0][i]=0;
        
        for(int i=1;i<=n;i++)
            for(int s=1;s<=sum;s++)
                {
                    //if(!i && s!=0)dp[i][s]=0;
                    if(arr[i-1]<=s)
                        dp[i][s] =  (dp[i-1][s]%m + dp[i-1][s-arr[i-1]]%m)%m;
                    else 
                        dp[i][s] = dp[i-1][s]%m; 
                }
                
        return dp[n][sum];
	}
	  
};