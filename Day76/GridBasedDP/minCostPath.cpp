/***************************************
*****Solution authored by Atlas25.******
*****************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int mod = 1e9 + 7;
const int N = 100005, M=22;
void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
            {
                if(!i && !j)dp[i][j]=cos[0][0];
                else if(!i)dp[i][j] = dp[0][j-1] + cost[0][j];
                else if(!j)dp[i][j] = dp[i-1][0] + cost[i][0];
                else  
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + cost[i][j]; 
            }
    
    return dp[R-1][C-1];
}
void init() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
int32_t main(){
    init();
        {
            int t;
            cin>>t;
            while(t--)
            solve();
        }
    }