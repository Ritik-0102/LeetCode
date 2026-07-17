class StockSpanner {
public:
    int idx;
    stack<int> s; // to store idx of prev smaller elements
    vector<int> prices; // to track prices

    StockSpanner() {
        idx = 0;
    }
    
    int next(int price) {
        prices.push_back(price);

        while(!s.empty() && price >= prices[s.top()]){
            s.pop();
        }

        int span;
        if(s.empty()){
            span = idx + 1;
        }
        else{
            span = idx - s.top();
        }

        s.push(idx);
        idx++;

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */