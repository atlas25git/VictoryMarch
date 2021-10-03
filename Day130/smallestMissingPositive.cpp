    int seg(vector<int>&nums)
    {
        int j=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]<=0)
                swap(nums[i],nums[j++]);
        return j;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        int s=seg(nums);
        
        for(int i=s;i<nums.size();i++)
        { 
           if(abs(nums[i])-1 < nums.size()-s) 
               if(nums[abs(nums[i])-1+s]>0)
                    nums[abs(nums[i])-1+s] *= -1;
        }
        
        for(int i=s;i<nums.size();i++)
                if(nums[i]>0)return i-s+1;
        
        return nums.size()+1-s;
        
    }