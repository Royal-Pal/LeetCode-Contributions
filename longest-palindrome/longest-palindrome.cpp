class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        
        unordered_map<char, int> um;
        
        for(int i = 0; i < n; i++) {
            um[s[i]]++;
        }
        
        int cnt = 0;
        unordered_map<char, int> :: iterator it;
        for(it = um.begin(); it != um.end(); it++) {
            cnt += (it->second & 1) ? (it->second - 1) : it->second;
        }
        
        if(cnt != n) {
            cnt++;
        }
        
        return cnt;
    }
};