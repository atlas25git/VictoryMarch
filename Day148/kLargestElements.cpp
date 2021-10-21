class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int> q;
        for(int i=0;i<n;i++)
        {   
            q.push(-arr[i]);
            if(q.size()>k)
                q.pop();
            
        }
        vector<int> res;
        while(q.size()!=0)
        {
            res.push_back(-q.top());
            q.pop();
        }
        sort(res.begin(),res.end(),greater<int>());
        return res;
    }
};