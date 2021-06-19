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
        cin>>n;
        stack<int> s;
        int ar[n];
        
        for(i=0;i<n;i++)cin>>ar[i];

        s.push(ar[0]);
        //cout<<-1<<" ";
        for(i=0;i<n;i++)
        {
            while(!s.empty() && ar[i]>=s.top())
            {   
                //cout<<"exec"<<endl;
                //cout<<s.top()<<"<-R"<<endl;
                s.pop();
            }

            if(s.size()>0)
                cout<<s.top()<<" ";
            else cout<<-1<<" ";

            s.push(ar[i]);
        }

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