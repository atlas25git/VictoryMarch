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
    //if only one step allowed:
        //Blocked cells present: N^2
            //1) fill in for i=0,j=0, with 1 ways
            //2) sum i,j-1 && i-1,j for i,j
            //3) if cell blocked fill for that 0 in dp array.

        //Recusrsive: Exponential complexity
            //1) f(x,y) = f(x-1,y) + f(x,y-1);
        //No Blocked cells:
            //1)(m-1 + n -1)!/(m-1)!*(n-1)!
    
    //More than one step allowed:
        //N^3 -> 2D version of dp problem
        //Take sum of dp[i][j] along rows and cols
        //for the given no of steps.
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