class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<int> dr = {-1,0,1,0,-1};
        stack<pair<int,int>> s;
        int prevColor;
        s.push({sr,sc});
        if(image[sr][sc] == color) return image;
        else prevColor = image[sr][sc];
        
        while(!s.empty()){
            pair<int,int> q = s.top(); s.pop();
            int i = q.first;
            int j = q.second;
            
            if(i>=0 and i<image.size() and j>=0 and j<image[0].size() and image[i][j] == prevColor){
                image[i][j] = color;
                for(int index = 0; index<4; index++){
                    s.push({i+dr[index], j+dr[index+1]});
                }
            }
        }
        
        return image;
    }
};