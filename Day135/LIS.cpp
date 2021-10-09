class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);
        
        for(int i=1;i<size(nums);i++)
        {
            if(nums[i]>lis.back())
                lis.push_back(nums[i]);
            else lis[lower_bound(lis.begin(),lis.end(),nums[i]) - lis.begin()] = nums[i];
        }
        
        // for(int i=1;i<size(nums);i++)
        // {
        //     lis[i] = 1;
        //     for(int j=0;j<i;j++)
        //         if(nums[j]<nums[i])
        //             lis[i] = max(lis[i],lis[j]+1);
        // }
        
        return lis.size();//*max_element(lis.begin(),lis.end());
    }
};