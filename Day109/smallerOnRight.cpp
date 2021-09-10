#include<bits/stdc++.h>
using namespace std;

int arr[100000];
set<int> s;

int cs(int n)
{
    int cs=0;
    for(int i=n-1;i>=0;i--)
    {
        s.insert(arr[i]);
        auto it = s.lower_bound(arr[i]);
        int dis = distance(s.begin(),it);
        if(dis>cs)
            cs=dis;
    }
    return cs;
}


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        s.clear();
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>arr[i];
        cout<<cs(n)<<endl;
    }
    return 0;
}