class Block {
public:
    int row;
    int clm;
    int time;
    
    Block(int row, int clm, int time) {
        this->row = row;
        this->clm = clm;
        this->time = time;
    }
};

class Solution {
public:
    bool insideBounds(int i, int j, int n, int m) {
        if(i >= 0 && j >= 0 && i < n && j < m) {
            return true;
        }
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        
        queue<Block> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push(Block(i, j, 0));
                }
            }
        }
        
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        while(!q.empty()) {
            Block b = q.front();
            ans = max(ans, b.time);
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int new_r = b.row + dir[i][0], new_c = b.clm + dir[i][1];
                
                if(insideBounds(new_r, new_c, n, m) && grid[new_r][new_c] == 1) {
                    grid[new_r][new_c] = 2;
                    q.push(Block(new_r, new_c, b.time + 1));
                }
            }
        }
        
        bool flag = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    ans = -1;
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        return ans;
    }
};