class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        if(nums.size()<3)return 0;
        sort(nums.begin(),nums.end());
        int i=0;
        while(nums[i]==0)i++;
        for(;i<nums.size();i++)
        {
            int k = i+2;
            for(int j=i+1;j<nums.size()-1;j++)
            {   
                //if(!nums[j])continue;
                while(k<nums.size() && nums[i] + nums[j] > nums[k])k++;
                ans += (k-1) - j;
                //the last increment in k is the breaking conditon
            }
        }
        return ans>0?ans:0;
    }
};