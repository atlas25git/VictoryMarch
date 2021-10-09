class Solution {
public:
    // unordered_map<int,int> dp;
    int coinChange(vector<int>& coins, int amount) {
        // dp.resize(amount+1,INT_MAX);
        vector<int>dp(amount+1,INT_MAX);
        
        if(!amount)return 0;
        //recCC(coins,amount);
        
        dp[0] = 0;
        
        for(auto c: coins)
            for(int i=1;i<=amount;i++)
            {
                if(c<=i)
                    if(dp[i-c]!=INT_MAX)
                        dp[i] = min(dp[i],dp[i-c]+1);
            }
        
        
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
    
    // int recCC(vector<int>& coins,int amt)
    // {
    //     if(amt<0)return INT_MAX;
    //     if(!amt)return 0;
    //     if(dp.count(amt))return dp[amt];
    //     int res=INT_MAX;
    //     for(auto x: coins)
    //         res = min(res,recCC(coins,amt-x));
    //     if(res==INT_MAX)return dp[amt] = res;
    //     else return dp[amt] = res+1;
    // }
};