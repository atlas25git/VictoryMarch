class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i==0 || (i && nums[i-1] != nums[i]))
            {
                int low = i+1,high = nums.size()-1,sum = -nums[i];
                while(low<high)
                {
                    int sumpr = nums[low] + nums[high];
                    
                    if(sumpr == sum)
                    {
                        res.push_back({nums[i],nums[low],nums[high]});
                        while(low<high && nums[low] == nums[low+1])low++;
                        while(low<high && nums[high] == nums[high-1])high--;
                        low++,high--;
                    }
                    else if(sumpr<sum)
                        low++;
                    else high--;
                }
            }
        }
        return res;
    }
};