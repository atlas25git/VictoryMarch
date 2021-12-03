class Solution
{   
    unordered_map<int,int> mp;
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
    {   
        sort(coins,coins+numberOfCoins);//,greater<int>());
        // int ways = cnt(coins,numberOfCoins,value);
        // return ways==INT_MAX?-1:ways;
        
        //Bottom up solution:
        //Since our recursive fn had just one param changing hence 1D grid 
        //will suffice.
        
        vector<int> dp(value+1,INT_MAX);
        
        //Base Case 
        dp[0]=0;
        
        for(int j=1;j<=value;j++)
            for(int i=0;i<numberOfCoins;i++)
                if(coins[i]<=j && dp[j-coins[i]]!=INT_MAX)
                    dp[j] = min(dp[j],dp[j-coins[i]]+1);
        
        return dp.back()!=INT_MAX?dp.back():-1;
    }
    
    
    long long cnt(int coins[],int n,int val)
    {   
        if(val<0 || n<=0)return INT_MAX;
        if(val == 0)return 0;
        if(mp.count(val))return mp[val];
        
        long long cnt1=INT_MAX,cnt2=INT_MAX;
        
        //Choose vs not choose will not work here as there will be redundant states
        //in our recursion tree whereby the necessary state won't be altering.
        // if(coins[n-1]<=val)
        //     cnt1 = min(cnt1,cnt(coins,n,val-coins[n-1]));
        // cnt2 = min(cnt1,cnt(coins,n-1,val));
        
        for(int i=0;i<n;i++)
            cnt1 = min(cnt1,cnt(coins,n,val-coins[i]));
        // long long cnt3 = min(cnt1,cnt2);
        
        if(cnt1 == INT_MAX)return mp[val] = cnt1;
        return mp[val] = cnt1+1;
    }
};