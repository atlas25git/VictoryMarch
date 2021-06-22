/***************************************
*****Solution authored by Atlas25.******
*****************************************/
#include<chrono>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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
        for(int i=0;i<999999;i++)cout<<i<<" ";
        cout<<endl;
        
}
void init() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
}
int32_t main(){
    init();
        {
        auto t0 = high_resolution_clock::now();
            int t;
            //cin>>t;
            //while(t--)
            solve();
            auto t1 = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(t1 - t0);
            cout << duration.count() << endl;

        }
    }