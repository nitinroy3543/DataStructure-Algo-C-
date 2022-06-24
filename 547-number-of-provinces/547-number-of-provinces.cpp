class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> friendZoned(M.size(), false);
        
        stack<int> dfs;
        
        int circles =0;
        
        for(int i=0; i<M.size(); i++){
            if(!friendZoned[i]){
                circles++;
                
                dfs.push(i);
                
                while(!dfs.empty()){
                    int current = dfs.top(); dfs.pop();
                    
                    friendZoned[current] = true;
                    
                    for(int j=0; j< M[current].size(); j++){
                        if(!friendZoned[j] && M[current][j] ==1){
                            dfs.push(j);
                        }
                    }
                    
                }
            }
        }
        return circles;
    }
};