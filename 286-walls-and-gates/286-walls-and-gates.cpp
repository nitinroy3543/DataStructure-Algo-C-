class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        vector<int> dr = {-1,0,1,0,-1};
        int m = rooms.size();
        int n = rooms[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rooms[i][j] == 0) q.push({i,j});
            }
        }
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                pair<int, int> p = q.front(); q.pop();
                
                int i = p.first;
                int j = p.second;
                
                for(int k=0; k<4; k++){
                    int n_i = i + dr[k];
                    int n_j = j + dr[k+1];
                    
                    if(n_i>=0 and n_i<m and n_j>=0 and n_j<n and rooms[n_i][n_j] != -1 and rooms[n_i][n_j] > (rooms[i][j]+1)){
                        rooms[n_i][n_j] = (rooms[i][j]+1);
                        q.push({n_i,n_j});
                    }
                }
            } 
        }
    }
};