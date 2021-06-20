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
        //naive approach:
        //consider every element as smaller and compute its area,
        //look for left and right sides till some smaller index is found.
        
        //optimized1:
        //next smaler and prvious smaller used.
        //now their indices will be stored, and hence the extra loop will not
        //be required.

        //optimized2:
        //

        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];

        stack<int> s;
        int res=0;
        for(int i=0;i<n;i++)
        {   
            //in the stack we store index of the previous smaller element;
            while(s.empty()==false && arr[s.top()]>=arr[i])
            {   
                //the arr[i], keep in mind is the next smaller element.
                int top = s.top();
                s.pop();
                ans = arr[top]*(s.empty()?i //indicating that i has no prev smaller element 
                                            : (i-s.top()-1));//computes the no. of places rectangular len extends 
            cnt = max(cnt,ans);
            }
            s.push(i);
        }

        //elements which do not have any next smaller
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            ans = arr[top]*(s.empty()?n:(n-s.top()-1));
            cnt = max(cnt,ans);
        }
        return res;
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