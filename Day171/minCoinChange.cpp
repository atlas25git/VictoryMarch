class Solution {
public:
    // unordered_map<int,int> dp;
    int coinChange1(vector<int>& coins, int amount) {
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
    
    
    //the so tried include exclude approach just doesn't work here
    //because in any ghiven case we're exploring the depth of it's reduction state space graph
    //and since it contains nodes where sometimes jsut the coin exclusion is presest,
    //and hence results in adding redundant coutns of coins
    
//     int coinChange(vector<int>& coins, int amount) {
//         int ways = cnt(coins.size(),coins,amount);
//         return ways==INT_MAX?-1:ways;
//     }
    
    
//     int cnt(int i,vector<int>& coins,int amount)
//     {
//         if(i <= 0 || amount<0)return 1e9;
//         if(!amount)return 0;
//         int inc=1e9,exc=1e9;
//         int res = 1e9;
        
//         if(coins[i-1]<=amount)
//             inc = cnt(i,coins,amount-coins[i-1]);
//         exc = cnt(i-1,coins,amount);
        
//         res = min({res,inc,exc});
//         if(res >= 1e9)return 1e9;
//         else return min(inc,exc)+1;
//     }
};