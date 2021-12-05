#define ll long long
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sum1Substrings(string s){
        
        vector<ll>dp(s.size()+1,0);
        dp[1]=s[0]-'0';
        ll res = dp[1];
        int m = 1e9+7;
        
        // sumofdigit[3] = 4 + 34 + 234 + 1234
        //               = 4 + 30 + 4 + 230 + 4 + 1230 + 4
        //               = 4*4 + 10*(3 + 23 +123)
        //               = 4*4 + 10*(sumofdigit[2])

        // In general, 
        //      i is on 1 based index
        //     sumofdigit[i] = (i)*num[i] + 10*sumofdigit[i-1]
        
        for(int i=2;s[i-1];i++)
        {
            int cd = s[i-1]-'0';
            
            dp[i] = ((cd*i)%m + (dp[i-1]*10)%m)%m;
            res = (res%m + dp[i]%m)%m;
        }
        
        return res;
    }
    long long sumSubstrings(string s){
        
        int m = 1e9+7;
        vector<ll> dp(s.size()+1);
        dp[0]=s[0]-'0';
        int res = dp[0];
        
        for(int i=1;s[i];i++)
        {
            int cd = s[i]-'0';
            dp[i] = ((cd*(i+1))%m + (dp[i-1]*10)%m)%m;
            res = (res%m + dp[i]%m)%m;
        }
        return res;
    }
};