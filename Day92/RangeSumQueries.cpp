// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

ll constructSTUtil(int *arr, int ss, int se, ll *st, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
             constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
    return st[si];
}

ll *constructST(int *arr, int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    ll *st = new ll[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

ll getsum(ll *st, int n, int l, int r);
void updateValue(int *, ll *, int, int, int);


 // } Driver Code Ends
// User function template for C++

// arr : given array
// n : size of arr
// index : need to update
// new_val : given value to which we need to update index
// st : constructed segment-tree

void util(ll* st,ll ss,ll se,ll df,ll si,ll i)
{
    if(i<ss || i>se)return;
    st[si] += df;
    if(se!=ss)
    {   int mid = ss + (se-ss)/2;
        util(st,ss,mid,df,2*si+1,i);
        util(st,mid+1,se,df,2*si+2,i);
    }
}

//Function to update a value in input array and segment tree.
void updateValue(int *arr, ll *st, int n, int index, int new_val) 
{
    if(index<0 || index>n-1)return;
    
    int df = new_val - arr[index];
    arr[index] = new_val;
    
    util(st,0,n-1,df,0,index);
}

//Function to return sum of elements in range from index qs (query start)
//to qe (query end).
ll gsum(ll* st,ll ss,ll se,ll l, ll r,ll si)
{
    //included node
    if(l<=ss && se <= r)return st[si];
    if(r<ss || l>se)return 0;
    
    int mid = ss + (se-ss)/2;
    
    return gsum(st,ss,mid,l,r,2*si+1) + 
            gsum(st,mid+1,se,l,r,2*si+2);
}

ll getsum(ll *st, int n, int l, int r)
{
    //invalid input
    if(l<0 || r>=n || l>r)return -1;
    return gsum(st,0,n-1,l,r,0);
}


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num, query;
        cin >> num >> query;
        int arr[num];
        for (int i = 0; i < num; i++) cin >> arr[i];

        ll *st = constructST(arr, num);
        int L, R, index, val;
        char type;
        while (query--) {
            cin.ignore(INT_MAX, '\n');
            cin >> type;
            if (type == 'G') {
                cin >> L >> R;
                cout << getsum(st, num, L, R) << endl;
            } else {
                cin >> index >> val;
                updateValue(arr, st, num, index, val);
            }
        }
    }

    return 0;
}
  // } Driver Code Ends