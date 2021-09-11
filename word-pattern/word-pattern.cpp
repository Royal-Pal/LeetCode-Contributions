class Solution {
public:
    bool wordPattern(string pat, string s) {
        int pat_len = pat.length();
        
        vector<string> v;
        stringstream check1(s);
        string tmp;
        
        while(getline(check1, tmp, ' ')) {
            v.push_back(tmp);
        }
        
        int v_len = v.size();
        
        if(pat_len != v_len) {
            return false;
        }
        
        unordered_map<char, string> cts;
        unordered_map<string, char> stc;
        
        for(int i = 0; i < v_len; i++) {
            if(cts.count(pat[i]) == 0 && stc.count(v[i]) == 0) {
                cts[pat[i]] = v[i];
                stc[v[i]] = pat[i];
                continue;
            }
            if(stc[v[i]] != pat[i]) {
                return false;
            }
        }
        
        return true;
    }
};