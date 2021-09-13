#define ll long long
class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        long long a=1,b=1;
        vector<ll>res;
        if(n>=1)res.push_back(a);
        if(n>=2)res.push_back(b);
        for(int i=3;i<=n;i++)
            {
            long long temp = a+b;
            res.push_back(a+b);
            a=b;
            b=temp;
            }
        return res;
    }
};