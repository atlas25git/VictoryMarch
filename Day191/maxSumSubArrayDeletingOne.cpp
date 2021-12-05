class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> fwd(nums.size(),0),bkd(nums.size(),0);
        if(nums.size()==1)return nums.front();
        int cm=0,msf=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++)
            cm = max(cm+nums[i],nums[i]),
            msf = max(msf,cm),
            fwd[i] = cm;
        cm = 0;
        for(int i=n-1;i>-1;i--)
            cm = max(nums[i],cm+nums[i]),
            bkd[i] = cm;
        int ans = msf;
        
        for(int i=0;i<n;i++)
            if(i==0)
                ans = max(ans,bkd[1]);
            else if(i == n-1)
                ans = max(ans,fwd[n-2]);
            else ans = max(ans,fwd[i-1] + bkd[i+1]);
        
        return ans;
    }
};