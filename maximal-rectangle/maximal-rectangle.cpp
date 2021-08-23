class Solution {
public:
    int maxAreaHis(int dp[], int n) {
        stack<int> st;
        
        vector<int> lse(n, -1);
        st.push(0);
        for(int i = 1; i < n; i++) {
            while(!st.empty() && dp[st.top()] >= dp[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                lse[i] = -1;
            } else {
                lse[i] = st.top();
            }
            
            st.push(i);
        }
        
        while(!st.empty()) {
            st.pop();
        }
        
        vector<int> rse(n, n);
        st.push(n - 1);
        for(int i = n - 2; i >= 0; i--) {
            while(!st.empty() && dp[st.top()] >= dp[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                rse[i] = n;
            } else {
                rse[i] = st.top();
            }
            
            st.push(i);
        }
        
        int max_area = 0;
        for(int i = 0; i < n; i++) {
            int width = rse[i] - lse[i] - 1;
            int curr_area = dp[i] * width;
            
            max_area = max(max_area, curr_area);
        }
        
        return max_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        
        if(n == 0) {
            return 0;
        }
        
        int m = matrix[0].size();

//         creating the dp array
        int dp[m];
        
//         initialise the dp array
        for(int j = 0; j < m; j++) {
            dp[j] = matrix[0][j] - '0';
        }
        
        int max_rectangle = maxAreaHis(dp, m);
        
        for(int i = 1; i < n; i++) {
            int curr_rectangle = 0;
            
//             filling the dp array
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '0') {
                    dp[j] = 0;
                } else {
                    dp[j] += 1;
                }
            }
            
            curr_rectangle = maxAreaHis(dp, m);
            max_rectangle = max(max_rectangle, curr_rectangle);
        }
        
        return max_rectangle;
    }
};