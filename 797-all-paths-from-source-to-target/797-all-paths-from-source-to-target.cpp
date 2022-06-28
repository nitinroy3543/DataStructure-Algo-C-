class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        int start = 0;
        int end = graph.size();
        vector<int> temp;
        temp.push_back(0);
        helper(result, graph, temp, 0);
        return result;
    }
    
    void helper(vector<vector<int>>& result, vector<vector<int>>& graph, vector<int>& temp, int start){
        if(start == graph.size()-1) {result.push_back(temp); return;}
        if(graph[start].size() == 0) return;
        
        for(auto x: graph[start]){
            temp.push_back(x);
            helper(result, graph, temp, x);
            temp.pop_back();
        }
    }
};