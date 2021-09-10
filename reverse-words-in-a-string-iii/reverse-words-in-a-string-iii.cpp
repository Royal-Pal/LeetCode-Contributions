class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        
        int low = 0, high = 0;
        while(high < n) {
            while(high < n && s[high] != ' ') {
                high++;
            }
            
            int tmp_h = high - 1;
            while(low < tmp_h) {
                swap(s[low++], s[tmp_h--]);
            }
            
            high++;
            low = high;
        }
        
        return s;
    }
};