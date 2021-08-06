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
    cin>>n>>sum;
    vector<int>arr(istream_iterator<int>(cin),{});
    
    int cs = 0;
    int start=0,end=0;

    for(i=0;i<n;i++)
    {
        cs+=arr[i];
        if(cs >= sum)
        {
            end = i;
            

            if(cs == sum)
            {
                cout<<"Start: "<<start+1<<endl;
                cout<<"End: "<<end+1<<endl;
                break;
            }
            else
            {
                while(cs > sum && start<end)
                {
                    cs -= arr[start++];
                }
            }

            
        }

    }
    return;
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
            // while(t--)
            solve();
        }
    }