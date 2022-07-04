class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> result(amount+1, INT_MAX);
        result[0] = 0;
        for(int i=0; i<=amount ;i++){
            for(auto coin: coins){
                if(coin<=i){
                    result[i] = min(result[i], result[i-coin] + 1);
                }
            }
        }
        return result[amount]>amount ? -1: result[amount];
    }
    
    
};