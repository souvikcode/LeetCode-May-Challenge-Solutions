class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
      if(s.empty())
      {
        mp[price] = 1;
        s.push(price);
        return 1;
      }
      int c = 0;
      while(!s.empty() && price >= s.top())
      {
        c += mp[s.top()];
        s.pop();
      }
      s.push(price);
      mp[price] = c+1;
      return mp[price];
    }
  private:
      map<int, int> mp;
      stack<int> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
