class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        stack<pair<int,int>> s;

        vector<int> dr = {-1,0,1,0,-1};
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, false));
        
        int maxsize = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
               if(visited[i][j] == false and grid[i][j] == 1){
                   s.push({i,j}); 
                   visited[i][j] = true;
                   int size = 0; 
                   while(!s.empty()){
                       pair<int,int> p = s.top(); s.pop();
                       int r = p.first;
                       int c = p.second;
                       size++;
                        maxsize = max(size, maxsize);
                       for(int k=0; k<4; k++){
                           int n_r= r+dr[k];
                           int n_c= c+dr[k+1];
                           
                           if(n_r>=0 and n_r<m and n_c>=0 and n_c<n and visited[n_r][n_c] == false and grid[n_r][n_c] == 1){
                              s.push({n_r,n_c});
                              visited[n_r][n_c] = true;
                              
                           }
                       }
                   }
               }  
            }
        }
        return maxsize;
    }
};