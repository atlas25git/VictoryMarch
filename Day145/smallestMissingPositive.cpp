int seg(vector<int>& nums)
    {
        int j=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]<=0)
                swap(nums[i],nums[j++]);
        return j;
    }
    
    int firstMissingPositive(vector<int>& nums)
    {   
        
        //the idea here is to first segragate the array from all the negative elements
        //and then use the remainig indices to use as markers for positive elements present
        //if any mark remains unmarked thus telling the missing no.
        //if none then the size+1 is the missing number
        
        int offset = seg(nums);
        
        for(int i=offset;i<nums.size();i++)
            if(abs(nums[i])-1<nums.size()-offset)
            if(nums[abs(nums[i])-1 + offset]> 0)
                nums[abs(nums[i])-1 + offset]*=-1;
        
        for(int i=offset;i<nums.size();i++)
        {
            if(nums[i]>0)
                return i-offset+1;
        }
        
        return nums.size()-offset+1;
    }