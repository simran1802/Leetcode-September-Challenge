class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0,max_curr=0;
        for(int c=1;c<prices.size();c++){
            res = max(0,res += prices[c]-prices[c-1]);
            max_curr = max(res,max_curr);
        }
        return max_curr;
    }
};
