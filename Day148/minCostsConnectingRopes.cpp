#define ll long long
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        priority_queue<ll,vector<ll>,greater<ll>>pq(arr,arr+n);
        ll res=0;
        while(pq.size()>1)
        {
            ll f=pq.top();pq.pop();
            ll s=pq.top();pq.pop();
            res += f+s;
            pq.push(f+s);
        }
        return res;
    }
};
