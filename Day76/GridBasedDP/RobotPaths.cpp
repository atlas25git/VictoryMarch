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

int dp[1001][1001];

int numWays(int R,int C)
{
    if(dp[0][0]==-1)return 0;
    for(int j=0;j<C;j++)
    {
        if(dp[0][j] == -1)break;
        dp[0][j]=1;
    }

    for(int i=0;i<R;i++)
    {
        if(dp[i][0]==-1)break;
        dp[i][0]=1;
    }

    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<C;j++)
        {
            if(dp[i][j] == -1)continue;

            //dp[i][j]=0;

            if(dp[i][j-1] !=-1)
                dp[i][j] = dp[i][j-1]%mod;
            if(dp[i-1][j] !=-1)
                dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
        }
    }
    if(dp[R-1][C-1] == -1)return 0;
    return dp[R-1][C-1];
}


void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        //given nxn matrix with i,j for the cells blocked
        //onwards a blocked cell all the following it will be zero/unreachable
        //in the i=0/j=0 case.
        memset(dp,sizeof(dp),0);
        cin>>m>>n>>k;
        for(i = 0;i<k;i++)
            {
                int x,y;
                cin>>x>>y;
                dp[x-1][y-1]=-1;
            }
        cout<<numWays(m,n)<<endl;
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
            solve();
        }
    }