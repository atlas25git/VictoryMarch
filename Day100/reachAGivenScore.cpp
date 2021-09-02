ll count(ll n) 
{
    vector<int> dp(n+1,0);
    
    dp[0]=1;
    //distinct combination thus order doesn't matter
    for(int i=3;i<=n;i++)
    {
        if(i-3>=0)
            //dp[i]+=1;
        //else 
        dp[i]+=dp[i-3];
    }
    for(int i=5;i<=n;i++)
     {
         if(i-5>=0)
            //dp[i]+=1;
        // else 
        dp[i]+=dp[i-5];
     }
    for(int i=10;i<=n;i++)
      {
         if(i-10>=0)//dp[i]+=1;
        // else 
        dp[i]+=dp[i-10];
      }
    return dp[n];
    
    
}