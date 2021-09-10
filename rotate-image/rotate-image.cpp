class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
//         swap over left diagonal
        int i = 0;
        while(i < n) {
            int tmp = 0;
            
            while(tmp < i) {
                swap(matrix[i][tmp], matrix[tmp][i]);
                tmp++;
            }
            
            i++;
        }
        
//         reverse individual rows
        for(int i = 0; i < n; i++) {
            int s = 0, e = n - 1;
            
            while(s < e) {
                swap(matrix[i][s], matrix[i][e]);
                s++;    e--;
            }
        }
        
        return;
    }
};