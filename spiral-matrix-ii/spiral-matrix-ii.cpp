class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > sol(n, vector<int>(n, 0));
        
        int row_s = 0, row_e = n - 1, clm_s = 0, clm_e = n - 1;
        int cnt = 1, loop = 0;
        
        bool isCompleted = false;
        while(!isCompleted) {
            isCompleted = true;
            
            switch(loop) {
                case 0: {
                    int j = clm_s;
                    while(j <= clm_e) {
                        isCompleted = false;
                        sol[row_s][j] = cnt;
                        j++;
                        cnt++;
                    }
                    row_s++;
                    loop = (loop + 1) % 4;
                    break;
                }
                    
                case 1: {
                    int i = row_s;
                    while(i <= row_e) {
                        isCompleted = false;
                        sol[i][clm_e] = cnt;
                        i++;
                        cnt++;
                    }
                    clm_e--;
                    loop = (loop + 1) % 4;
                    break;
                }
                    
                case 2: {
                    int j = clm_e;
                    while(j >= clm_s) {
                        isCompleted = false;
                        sol[row_e][j] = cnt;
                        j--;
                        cnt++;
                    }
                    row_e--;
                    loop = (loop + 1) % 4;
                    break;
                }
                    
                case 3: {
                    int i = row_e;
                    while(i >= row_s) {
                        isCompleted = false;
                        sol[i][clm_s] = cnt;
                        i--;
                        cnt++;
                    }
                    clm_s++;
                    loop = (loop + 1) % 4;
                    break;
                }
            }
        }
        // cout << row_s << " " << clm_s;
        // cout << "\n" << row_e << " " << clm_e;
        
        return sol;
    }
};