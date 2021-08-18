class Solution {
public:
    
    void helper(vector<vector<int> > &image, int sr, int sc, int n, int m, int color, int new_clr) {
        if(sr < 0 || sc < 0 || sr >= n || sc >= m) {
            return;
        }
        if(image[sr][sc] != color || image[sr][sc] == new_clr) {
            return;
        }
        
        image[sr][sc] = new_clr;
        
        helper(image, sr, sc - 1, n, m, color, new_clr);
        helper(image, sr, sc + 1, n, m, color, new_clr);
        helper(image, sr - 1, sc, n, m, color, new_clr);
        helper(image, sr + 1, sc, n, m, color, new_clr);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size(), color = image[sr][sc];
        
        helper(image, sr, sc, n, m, color, newColor);
        
        return image;
    }
};