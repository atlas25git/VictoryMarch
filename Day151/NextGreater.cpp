class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long > s;
        vector<long long > res (n);
        
        for (int i = n-1; i >= 0; i--)
        {   
            //for the last element the answer would be -1
            //for other we'll in the iteration prior to it will store it in stack
            //now for the current element int question we will pop
            //items till the element on top is greater than the current element 
            //in question.
            
            while (!s.empty () and s.top () <= arr[i])
                s.pop();
            if (s.empty())
                res[i] = -1;
            else 
                res[i] = s.top();
            s.push (arr[i]);
        }
        return res;
    }
};