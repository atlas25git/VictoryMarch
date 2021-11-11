class Solution
{   
    private:
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    double median = 0;
    
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(max.empty())max.push(x);
        else if(x>max.top())min.push(x);
        else if(x<=max.top())
        {
            //if it's second insertion and min is empty
            //since at any given point the abs diff b/2 both
            //the heaps would be <= 1
            if(min.empty())
                min.push(max.top()),
                max.pop(),
                max.push(x);
            else
                max.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(abs(max.size() - min.size()) > 1)
        {
            if(max.size() > min.size())
                min.push(max.top()),
                max.pop();
            else if(min.size() > max.size())
                max.push(min.top()),
                min.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if((max.size() + min.size())%2 == 0)
            median = (max.top() + min.top())/2.0;
        else {
            if(min.size() > max.size())
                median = min.top();
            else median = max.top();
        }
        return median;
    }
};