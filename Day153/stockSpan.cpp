class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       vector<int> ans;
       stack<int> s;
    //   s.push(0);
    //   ans.push_back(1);
       
       for(int i=0;i<n;i++)
       {    
           //maintaining previous greater elements.
           while(!s.empty() && arr[s.top()] <= arr[i])s.pop();
           int span = s.empty()?i+1:(i-s.top());
           ans.push_back(span);
           s.push(i);
       }
       return ans;
    }
};