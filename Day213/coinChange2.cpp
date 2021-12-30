class Solution {
public:
    int ans;
    int n;
    vector<vector<int>> memo;
    unordered_map<int,int> memoOrd;
    vector<int> c;
    
    int change(int amount,vector<int>& coins) {
        n = coins.size();
        ans = 0;
        c.swap(coins);
        
        memo.resize(amount+1,vector<int>(n+1,0));
        
        //unordered_Sets:
        //---------------
        //return ccRec(amount,n);
       
        //ordered sets:
        //-------------
            // int x = ccRecOrd(amount);
            // cout<<x<<" ans: "<<ans<<"\n";
            // return x;
        //Only one parameter changing hence could be solved using 1D dp.
        
        
        //Bottom Up:
        
        memo[0][0] = 1;
        
        for(int j=0;j<=amount;j++)
            for(int i=0;i<=n;i++)
            {
                if(!i)
                    memo[j][i] = 0;
                else if(!j)
                    memo[j][i] = 1;
                else if(coins[i-1] <= j)
                    memo[j][i] = memo[j][i] + 
                                 memo[j][i-1] + 
                                //Not including the coin, since infinite
                                //supply hence keeping the coin row same, as in
                                //limited supply case we'd have used the row 
                                //corresponding to reduced state of coins.
                                 memo[j-coins[i-1]][i];
                else memo[j][i] += memo[j][i-1];
            }
       
        return memo[amount][n]; 
         
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
//         return dp[amount];
    }
    
    void printmat(vector<vector<int>> & memo)
    {
         for(auto x: memo)
        {
            for(auto y : x)
                cout<<y<<" ";
            cout<<endl;
        }
    }
    
    //Counting sets where order matters.
    int ccRecOrd(int amt)
    {
        if(!amt)
            {
                ans++;
                return 1;
            }
        
        int cnt = 0,res=INT_MAX;
        for(auto x: c)
        {
            if(x<=amt)
                cnt += ccRecOrd(amt-x);
        }
        return cnt;
    }
    
    
    // choose vs not choose so that unordered pairs are counted, with unltd supply.
    int ccRec(int amt,int n)
    {
        if(n==0)return 0;
        if(!amt) return 1;
        if(memo[amt][n] != INT_MAX)return memo[amt][n];
        int a=0,b=0;
        b = ccRec(amt,n-1);
        if(c[n-1]<=amt)
            a = ccRec(amt-c[n-1],n);
            // cout<<a+b<<"\n";
        return memo[amt][n] = a+b;
    }
};