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

void fillLPS(string s,int* lps)
{
    int n=s.size(),len=0;
    lps[0]=0;
    int i=1;
    while(i<n){
        if(s[i]==s[len])
        {   
            len++; 
            lps[i]=len;
            i++;
        }
        else{
            if(len==0){
                lps[i]=0;i++;
            }
            else{
                len=lps[len-1];
            }
        }
    }
}   

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        //we use precomputed lps value of len
        string s;
        cin>>s;
        int lps[s.size()];
        fillLPS(s,lps);
        for(auto x:lps)cout<<x<<"\n";
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