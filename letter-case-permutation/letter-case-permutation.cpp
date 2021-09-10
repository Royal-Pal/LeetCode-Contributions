class Solution {
public:
    void rec(string str, int i, vector<string> &v) {
        if(i == str.length()) {
            v.push_back(str);
            return;
        }
        
        if(str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
            rec(str, i + 1, v);
            str[i] = str[i] - 32;
        }
        if(str[i] >= 97 && str[i] <= 122) {
            str[i] = str[i] - 32;
            rec(str, i + 1, v);
            str[i] = str[i] + 32;
        }
        
        rec(str, i + 1, v);
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> v;
        
        rec(s, 0, v);
        
        return v;
    }
};