//basically the idea here is that we maintain 2 sets of stream elements encountered.
//Now at any given instance if the number is odd the smaller set containig the extra element
//will have median as it's largest element.
//In other cases we'll return mean of both the tops.

//Points to be kept in mind:
    //Maintaing the two sets would require max heap for the smaller, and min for the larger.
    //The insertion flow will depend on the size criteria of both the sets.
    //And ascertaining to respective top elements.

class MedianFinder {
    priority_queue<int> s;
    priority_queue<int,vector<int>,greater<int>> g;
    double median;
public:
    MedianFinder() {
        median  = 0;
    }
    
    void addNum(int num) {
        if(s.empty())
            s.push(num);
        else if(s.size()>g.size())
        {
            if(s.top()>num)
            {
                g.push(s.top());
                s.pop();
                s.push(num);
            }
            else g.push(num);
        }
        else
        {
            if(s.top()>num)
                s.push(num);
            else
            {
                g.push(num);
                s.push(g.top());
                g.pop();
            }
        }
    }
    
    double findMedian() {
        if(s.size() == g.size())
                return (s.top() + g.top())/2.0;
        else return s.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */