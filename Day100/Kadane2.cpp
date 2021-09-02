class Solution
{
    public:
    //Function to return the maximum sum without adding adjacent elements.
    long long maximumSum(int arr[], int s)
    {
      int msf = INT_MIN;
      int c = 0;
      for(int i=0;i<s;i++)
            {
                if(arr[i]<0)c++;
                msf = max(msf,arr[i]);
            }
            if(c==s)return msf;
            vector<int>dp(s+1,0);
            dp[0]=arr[0]<0?0:arr[0];
            dp[1]=max(arr[1],dp[0]);
            msf=INT_MIN;
            for(int i=2;i<s;i++)
            {
                dp[i] = max(arr[i]+dp[i-2],dp[i-1]);
                msf = max(msf,dp[i]);
            }
            return msf;
    }
};
