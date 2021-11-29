class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        //since we need to return a subarray that being continguous in nature
        //hence we can intially start the sum computation from right and then 
        //when it becomes gr8r than sum we've got only one option that is to
        //reduce from the right.
        long long sum=0;
        int start=0,end=0;
        
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum>=s)
            {
                end = i;
                while(sum>s && start<=end)
                    sum-=arr[start++];
                if(sum == s)
                    return vector<int>({start+1,end+1});
            }
        }
        return vector<int>({-1});
    }
};