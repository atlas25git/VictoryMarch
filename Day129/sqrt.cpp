#define ll long long 
class Solution {
public:
    int mySqrt(int x) {
        if(!x)return x;
        ll i = 1,j=x;
        long long ans = INT_MIN;
        while(i<=j)
        {
            ll mid = i + (j-i)/2;
            ll pw = mid*mid;
            if(pw<=x)
            {
                ans = max(ans,mid);
                i = mid + 1;
            }else j = mid-1;
            
        }
        
        return ans;
    }
};