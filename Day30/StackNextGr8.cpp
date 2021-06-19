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
        stack<int> s,s1;
        int ar[n];
        
        for(i=0;i<n;i++)cin>>ar[i];

        s.push(ar[n-1]);
        s1.push(-1);
        //cout<<-1<<" ";
        for(i=n-2;i>=0;i--)
        {
            while(!s.empty() && ar[i]>=s.top())
            {   
                //cout<<"exec"<<endl;
                //cout<<s.top()<<"<-R"<<endl;
                s.pop();
            }
            //cout<<"Answers"<<endl;
            if(s.size()>0)
                s1.push(s.top());
                //cout<<s.top()<<" ";
            else s1.push(-1);//cout<<-1<<" ";

            s.push(ar[i]);
        }
        while(s1.empty()!=1)
        {
            cout<<s1.top()<<" ";
            s1.pop();
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