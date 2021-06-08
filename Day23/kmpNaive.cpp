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

int lps(string s,int n)
{
    for(int i=n-1;i>=0;i--)
    {
        bool flag=true;
        for(int j=0;j<i;j++)
            if(s[j]!=s[n-i+j])flag=false;
        if(flag)return i;
        //case is optimally garunteed as we're checking in decreasing manner
    }
    return -1;
}


void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        string s;

        cin>>s;
        int ar[s.size()];
        
        for(int i=0;i<s[i];i++)
            ar[i]=lps(s,i);

        for(auto x:ar)cout<<x+1<<endl;
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
            // int t;
            // cin>>t;
            //while(t--)
            solve();
        }
    }