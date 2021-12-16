class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        //converting k to 0 based index
        k--;
        for(int i=0;i<nums.size();i++)
        {
            while(dq.size() && dq.front()<(i-k))dq.pop_front();
            while(dq.size() && nums[dq.back()] <= nums[i])dq.pop_back();
            
            dq.push_back(i);
            if(i>=k)
                res.push_back(nums[dq[0]]);
        }
        return res;
    }
};