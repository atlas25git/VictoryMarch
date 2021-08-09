/***************************************
*****Solution authored by Atlas25.******
*****************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second

#define pb push_back
const int mod = 1e9 + 7;
const int N = 100005, M=22;


int P(int m, int n) {
    int ans = 1;
    for (int i = m - n + 1; i <= m; ++i)
      ans *= i;
    return ans;
  }

int numD(int N) {
    int uniqueNumbers = 0;
    vector<int> digits;  // N + 1
    unordered_set<int> seen;

    // transfer N + 1 to an array of digits
    for (int i = N + 1; i > 0; i /= 10)
      digits.push_back(i % 10);
    reverse(begin(digits), end(digits));

    const int n = digits.size();

    // unique numbers w/ digits < n
    for (int i = 1; i < n; ++i)
      uniqueNumbers += 9 * P(9, i - 1);

    // unique numbers w/ digits = n and same prefix
    for (int i = 0; i < n; ++i) {
      for (int j = i > 0 ? 0 : 1; j < digits[i]; ++j)
        if (!seen.count(j))
          uniqueNumbers += P(9 - i, n - i - 1);
      if (seen.count(digits[i]))
        break;
      seen.insert(digits[i]);
    }

    return N - uniqueNumbers;
  }



void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>i>>j;
        int ansi = numD(i);
        int ansj = numD(j);

        cout<<((j-i)-(ansj-ansi) + 1)<<endl;

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