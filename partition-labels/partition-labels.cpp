class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        
        vector<int> v;
        
        unordered_map<char, int> um;
        
        for(int i = n - 1; i >= 0; i--) {
            if(um.count(s[i]) == 0) {
                um[s[i]] = i;
            }
        }
        
        // for(auto i : um) {
        //     cout << i.first << ": " << i.second << "\n";
        // }
        
        int i = 0;
        while(i < n) {
            int last_occ = um[s[i]];
        
            int j = i;
            while(j < last_occ) {
                last_occ = max(last_occ, um[s[j]]);
                j++;
            }
            
            v.push_back(j - i + 1);
            i = j + 1;
        }
        
        return v;
    }
};