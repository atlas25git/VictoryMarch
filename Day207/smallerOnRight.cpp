#include <bits/stdc++.h>
using namespace std;

int c = 0;
vector<int> ans;

void merge(vector<pair<int,int>>&a ,int i,int m,int j)
{
    auto fill = [&a](vector<pair<int,int>>& tmp,int i1,int j1) -> void
    {
        for(int x=i1;x<=j1;x++)
            tmp.push_back(a[x]);
    };
    vector<pair<int,int>> lt,rt;
    rt.clear(),lt.clear();
    fill(lt,i,m),fill(rt,m+1,j);


    
    int x =0,y=0,k=i;
    int rtos = 0;
    
    while(x<lt.size() && y<rt.size())
    {
        if(lt[x]<rt[y])
            a[k++] = lt[x],
            ans[lt[x++].second] += rtos;
        else if(lt[x] > rt[y])
            a[k++] = rt[y++],
            rtos++;
    }
    
    while(x<lt.size())
        a[k++] = lt[x],
        ans[lt[x++].second] += rtos;
    while(y<rt.size())
        a[k++] = rt[y++];
    
    return;
}


void mergeSort(vector<pair<int,int>>& a,int i,int j)
{
    if(i>=j)
        return;
    int m = i + (j-i)/2;
    mergeSort(a,i,m);
    mergeSort(a,m+1,j);
    merge(a,i,m,j);
}


int solve(vector<pair<int,int>>& a)
{
    c = 0;
    
    mergeSort(a,0,a.size()-1);
    
    return c;
    
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ans.clear();
        ans.resize(n);
        vector<int> ab(n);
        for_each(ab.begin(),ab.end(),[](int& x){cin>>x;});
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++)a.push_back({ab[i],i});
        solve(a);
        cout<<*max_element(ans.begin(),ans.end())<<"\n";
        // cout<<endl;
    }
    return 0;
}