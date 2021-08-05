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
        //in a grid we've to come up with a soln such that the maximum min is possible
        //brute force:
            //at every i,j make a cut and thus find the sums of all the 4 quadrants
             //this approach will take N^2 in traversal
             //and N^2 in sum cal
        //We can come up with an optimization for the sum computation part, for which we
        //use dp.
        //we can store smaller instances of sub matrices.
        
        //Prefix sum dp:
        //--------------
        //Recurrence:
        //dp[x,y] = dp[x,y-1] + dp[x-1,y] - dp[x-1][y-1] +1/0{arr[x][y]};
        //Now the sum part could be done in O(1) thus the problem's complexity
        //reduces to O(N^2)
         

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