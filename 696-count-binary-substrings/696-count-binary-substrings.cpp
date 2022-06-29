class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0;
        int next =0;
        int count = 0;
        for(int i=0 ;i<s.size(); ){
            prev = next;
            next = 0;
            if(s[i] == '0')
                while(s[i] == '0') {next++; i++;}
            else
                while(s[i] == '1') {next++; i++;}
            
            count += min(next, prev);
        }
        return count;
    }
};