class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        
        for(int i=0; i<prerequisites.size(); i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<bool> todo(numCourses), done(numCourses);
        
        for(int i=0; i<numCourses; i++){
            if(!done[i] and !acyclic(adjList,todo, done, i)){
                return false;
            }
        }
        
        return true;
    }
    
    bool acyclic(vector<vector<int>>& adjList, vector<bool>& todo, vector<bool>& done, int i){
        if(todo[i]) return false;
        
        if(done[i]) return true;
        
        todo[i] = true;
        for(auto v: adjList[i]){
            if(!acyclic(adjList, todo, done, v)){
                return false;
            }
        }
        done[i] = true;
        todo[i] = false;
        return true;
    }
};