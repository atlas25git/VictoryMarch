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

void maxHeapify(int arr[],int n,int i)
{
    int p=i,l=2*i+1,r=2*i+2;
    if(l<n && arr[l]>arr[p])p=l;
    if(r<n && arr[r]>arr[p])p=r;
    if(p!=i)
    {
        swap(arr[p],arr[i]);
        maxHeapify(arr,n,p);
    }

}

void hsort(int arr[],int n)
{
    for(int i=((n-1)-1)/2;i>=0;i--)
    //since arr[0] has been modified
    //we call thus heapify on it
        maxHeapify(arr,n,i);
}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)cin>>arr[i];
        hsort(arr,n);
        for(i=n-1;i>=1;i--)
        {
            swap(arr[0],arr[i]);
            maxHeapify(arr,i,0);
        }

        for(i=0;i<n;i++)cout<<arr[i]<<endl;


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