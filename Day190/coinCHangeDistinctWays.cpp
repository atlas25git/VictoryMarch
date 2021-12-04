#define ll long long
// #define dp memo
class Solution {
public:
    int n;
    vector<vector<ll>> memo;
     vector<vector<ll>> memo1;
    
    int change(int amount,vector<int>& coins) {
        n = coins.size();
        // memo.resize(n+1,vector<ll>(amount+1,0));
        memo1.resize(amount+1,vector<ll>(n+1,0));
    
        // memo[0][0]=1;

//         for(int i=0;i<=n;i++)
//             for(int j=0;j<=amount;j++)
//             {   
                
                
//                 if(!i && j)
//                     memo[i][j] = 0;
//                 else if(!j)
//                     memo[i][j] = 1;
//                 else if(coins[i-1]<=j)
//                     memo[i][j] += memo[i-1][j] + memo[i][j-coins[i-1]];
//                 else 
//                     memo[i][j] += memo[i-1][j];
//             }
        
        for(int i=0;i<=n;i++)memo1[0][i]=1;
        // for(int i=1;i<=amount;i++)memo1[i][0]=0;
        
        for(int j=1;j<=amount;j++)
            for(int i=1;i<=n;i++)
            {
                memo1[j][i] += memo1[j][i-1];
                if(coins[i-1]<=j)
                    memo1[j][i] += memo1[j-coins[i-1]][i];
            }
        
        
        printMat(memo1);
        //     //ccRec(coins,amount,n);
        // int ans;
        // for(int i=0;i<=n;i++)
        //     ans+=memo[amount][i];
        // return ans; 
        
        //since the supply of coins here is infinite hence an unbounded kpSack
        //thus the extra dimension could be skipped
        
//         vector<int> dp(amount+1,0);
//         dp[0] = 1;
        
//         for(auto c : coins)
//             for(int i=0;i<=amount;i++)
//             {
//                 if(c<=i)
//                     dp[i] += dp[i-c];
            
//             }
//         cout<<endl;        
//         for(auto x: dp)cout<<x<<" ";
//         // return dp[amount];
        return 0;
    }

    
    void printMat(vector<vector<ll>> & memo)
    {
         for(auto x: memo)
        {
            for(auto y : x)
                cout<<y<<" ";
            cout<<endl;
        }
    }
    
    // int ccRecOrd(vector<int>& c,int amt, int n)
    // {
    //     if(!amt)return 1;
    //     if(!n)return 0;
    //     int a=0,b=0;
    //     if(amt<=c[n-1])
    //         a = ccRecOrd(a)
    // }
    int ccRec(vector<int>& c,int amt,int n)
    {
        if(n==0)return 0;
        if(!amt) return 1;
        if(memo[amt][n] != INT_MAX)return memo[amt][n];
        int a=0,b=0;
        b = ccRec(c,amt,n-1);
        if(c[n-1]<=amt)
            a = ccRec(c,amt-c[n-1],n);
        return memo[amt][n] = a+b;
    }
};