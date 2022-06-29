class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        
        for(int j=0; j < queries.size(); j++){
            bool flag = true;
            int i = 0;
            for(int k = 0; k < queries[j].length(); k++){
                if(i < pattern.length() and pattern[i] == queries[j][k]) i++;
                else if (queries[j][k] < 'a') flag= false;
            }
            if(i < pattern.length()) flag = false;
            result.push_back(flag);
        }
        return result;
    }
};