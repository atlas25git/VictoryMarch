class StockSpanner {
public:
    //to find out the span of a stack in one traversal we basically need to
    //maintain the previous greater element, hence the distance/span could be computed
    //in O(1) then
    
    vector<int> aux;
    stack<int> st;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        aux.push_back(price);
        while(!st.empty() && aux[st.top()]<=price)st.pop();
        int span = st.empty()?aux.size():aux.size()-st.top()-1;//0,1 based indexing
        st.push(aux.size()-1);//this will hence act as the prev gr8r chk for futrther elements/
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */