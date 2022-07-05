class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> result(2, vector<int> (matrix[0].size(),0));
        result[0] = matrix[0];
        for(int j=1; j<matrix.size();j++){
            for(int i=0; i<matrix[0].size(); i++){
                int p1=INT_MAX, p2=INT_MAX, p3=INT_MAX;
                if(i>0) p1 = result[0][i-1];
                if(i<matrix[0].size()-1) p2 = result[0][i+1];
                p3 = result[0][i];
                result[1][i] = min(p1,min(p2,p3)) + matrix[j][i];
            }
            result[0] = result[1];
        }
        int minv = INT_MAX;
        for(int i=0; i<result[0].size(); i++){
            minv = min(minv, result[0][i]);
        }
        return minv;
        
    }
};