class Solution {
public:
    int r,c;
    vector<vector<bool>> visited;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int closedIsland(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        visited = * new vector<vector<bool>>(r, vector<bool>(c, false));
        
        int output = 0;
        
        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                if(grid[i][j] == 0 && !visited[i][j]) {
                    bool isValid = true;
                    dfs(grid, i, j, isValid);
                    if(isValid)
                        output++;
                }
            }
        }
        return output;
    }
    
    void dfs(vector<vector<int>>& grid, int ui, int uj, bool& isValid) {
        visited[ui][uj] = true;
        if(ui == 0 || ui == r-1 || uj == 0 || uj == c-1) {
            isValid = false;
        }
        for(auto& [di, dj] : dirs) {
            int vi = ui + di;
            int vj = uj + dj;
            if(vi >= 0 && vi < r && vj >=0 && vj < c && grid[vi][vj] == 0 && !visited[vi][vj]) {
                dfs(grid, vi, vj, isValid);
            }
        }
    }
    
};