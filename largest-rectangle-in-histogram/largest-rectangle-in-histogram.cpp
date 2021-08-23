class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> st;
        
        int lse[n];
        lse[0] = -1;
        st.push(0);
        
        for(int i = 1; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                lse[i] = -1;
            } else {
                lse[i] = st.top();
            }
            
            st.push(i);
        }
        
//         clearing the stack
        while(!st.empty()) {
            st.pop();
        }
        
        int rse[n];
        rse[n - 1] = n;
        st.push(n - 1);
        
        for(int i = n - 2; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                rse[i] = n;
            } else {
                rse[i] = st.top();
            }
            
            st.push(i);
        }
        
//         for(int i = 0; i < n; i++) {
//             cout << lse[i] << " ";
//         } cout << "\n";
        
//         for(int i = 0; i < n; i++) {
//             cout << rse[i] << " ";
//         } cout << "\n";
        
        int max_area = 0;
        for(int i = 0; i < n; i++) {
            int width = rse[i] - lse[i] - 1;
            int curr_area = width * heights[i];
            
            if(curr_area > max_area) {
                max_area = curr_area;
            }
        }
        
        return max_area;
    }
};