class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int s = 0,e=sum;
        int ans = INT_MAX;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(isP(nums,m,mid))
                ans = min(ans,mid),
                e = mid-1;
            else s = mid+1;
        }
        return ans;
    }
    
    bool isP(vector<int>& nums,int m,int mid)
    {
        int req = 1;
        int cs = 0;
        for(auto x:nums)
        {
            if(x>mid)return 0;
            if(x+cs<=mid)cs+=x;
            else req++,cs=x;
            if(req>m)return 0;
        }
        return 1;
    }
};