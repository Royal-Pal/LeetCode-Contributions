class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        
        int row = 0, clm = m - 1;
        
        while((row >= 0 && row < n) && (clm >= 0 && clm < m)) {
            if(mat[row][clm] == target) {
                return true;
            } else if(mat[row][clm] < target) {
                row++;
            } else {
                clm--;
            }
        }
        
        return false;
    }
};