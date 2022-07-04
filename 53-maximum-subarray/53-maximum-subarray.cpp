class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0, result=INT_MIN;
        for(auto c: nums){
            sum = max(c, c+ sum);
            result = max (sum, result); //if(sum > result) result = sum;
        }
        return result;
    }
};