class Solution {
public:
    int editDist(string& w1, string& w2, int n, int m, vector<vector<int>>& memo) {
        if(n == 0) return m;
        if(m == 0) return n;
        if(memo[n][m] != -1) return memo[n][m];
        
        if(w1[n-1] == w2[m-1]) {
            memo[n][m] = editDist(w1, w2, n-1, m-1, memo);
            return memo[n][m];
        }
        else{
            memo[n][m] = 1 + min({editDist(w1, w2, n, m-1, memo), editDist(w1, w2, n-1, m, memo), editDist(w1, w2, n-1, m-1, memo)});
            return memo[n][m];
        }
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
        return editDist(word1, word2, n, m, memo);
    }
};