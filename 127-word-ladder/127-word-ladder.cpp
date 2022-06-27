class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wset(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        int ans =1;
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                beginWord = q.front();
                q.pop();
                if(beginWord == endWord) return ans;
                
                for(int i=0; i< beginWord.length(); i++){
                    char oChar = beginWord[i];
                    
                    for(char c='a'; c<='z'; c++){
                        beginWord[i] = c;
                        if(wset.find(beginWord) != wset.end()){
                            q.push(beginWord);
                            wset.erase(wset.find(beginWord));
                        }
                    }
                    beginWord[i] = oChar;
                }
            }
            ans++;
        }
        return 0;
    }
};