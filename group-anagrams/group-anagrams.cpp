class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string> > ans;
        
        map<map<char, int>, int> um;
        
        for(int i = 0; i < n; i++) {
            string s = strs[i];
            map<char, int> tmp;
            
            for(int j = 0; j < s.length(); j++) {
                tmp[s[j]]++;
            }
            
            if(um.count(tmp) > 0) {
                ans[um[tmp]].push_back(s);
            } else {
                vector<string> v = {s};
                ans.push_back(v);
                um[tmp] = ans.size() - 1;
            }
        }
        
        return ans;
    }
};