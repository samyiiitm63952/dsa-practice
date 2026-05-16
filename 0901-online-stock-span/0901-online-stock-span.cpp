class StockSpanner {
public:
    vector<int>span;
    StockSpanner() {
        
    }
    
    int next(int price) {
        span.push_back(price);
        int cnt=0;
        for(int i=span.size()-1;i>=0;i--){
            if(span[i]<=price){
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */