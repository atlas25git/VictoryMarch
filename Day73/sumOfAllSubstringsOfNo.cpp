#define ll long long
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        vector<ll>dp(s.size()+1,0);
        dp[1]=s[0]-'0';
        ll res = dp[1];
        int m = 1e9+7;
        for(int i=2;s[i-1];i++)
        {
            int cd = s[i-1]-'0';
            
            dp[i] = ((cd*i)%m + (dp[i-1]*10)%m)%m;
            res = (res%m + dp[i]%m)%m;
        }
        
        return res;
    }
};


#define ll long long
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        vector<ll>dp(s.size()+1,0);
        //our dp[i] will store sum of substrings ending at i
        //this will thus have for 1234
        //dp[1] = 1
        //dp[2] = 2 + 12 //hence i*(unit digit) + dp[i-1]%10
        
        dp[1]=s[0]-'0';
        ll res = dp[1];
        int m = 1e9+7;
        
        for(int i=2;s[i-1];i++)
        {
            int cd = s[i-1] - '0';
            
            dp[i] = (((i*cd))%m + (dp[i-1]*10)%m)%m;
            
            res = (res+dp[i])%m;
            
        }
        return res;
        
     }
};