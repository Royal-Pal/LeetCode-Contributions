class Solution {
public:
    void reverseString(vector<char>& v) {
        int n = v.size();
        
        int s = 0, e = n - 1;
        while(s < e) {
            swap(v[s], v[e]);
            s++;    e--;
        }
        
        return;
    }
};