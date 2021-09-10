class Solution {
    #define mp make_pair
    #define ff first
    #define ss second
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int> > dist(n, vector<int>(m, INT_MAX));
        
        queue<pair<int, int> > q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push(mp(i, j));
                }
            }
        }
        
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int new_r = p.ff + dir[i][0], new_c = p.ss + dir[i][1];
                
                if(new_r >= 0 && new_c >= 0 && new_r < n && new_c < m) {
                    if(dist[new_r][new_c] > dist[p.ff][p.ss]) {
                        dist[new_r][new_c] = 1 + dist[p.ff][p.ss];
                        q.push(mp(new_r, new_c));
                    }
                }
            }
        }
        
        return dist;
    }
};