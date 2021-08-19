#define ll long long
class Solution {
  public:
    long long numberOfWays(long long n) {
          ll mod = 1e9+7;
        ll a;ll b;ll c=0;ll tmp;
        a=1,b=1;
        
        for(int i=2;i<=n;i++)
            {
            c = (a%mod+b%mod)%mod,
            tmp = b,
            b = c,
            a = tmp,
            tmp=0;
            }
        if(n==1||n==2)return n;
        return c%mod;  
    }
};