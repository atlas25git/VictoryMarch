class Solution
{   double median = 0;
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(max.empty())
            max.push(x);
        else if(x > max.top())
            min.push(x);
        else if(min.empty()) //&& x<max.top())//second clause redundant
            min.push(max.top()),
            max.pop(),
            max.push(x);
        else
            max.push(x);
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(abs(max.size() - min.size()) > 1)
        {
            if(max.size() > min.size())
            {
                min.push(max.top());
                max.pop();
            }
            else{
                max.push(min.top());
                min.pop();
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if((max.size() + min.size())%2 == 0)
        {
            median = max.top() + min.top();
            median /= 2;
        }
        else{
            if(min.empty())
                median = max.top();
            else if(min.size() < max.size())
                median = max.top();
            else 
                median = min.top();
        }
        
        return median;
    }
};
