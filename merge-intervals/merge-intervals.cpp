class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(), 
            [](vector<int> a, vector<int> b) -> bool {
                return a[0] < b[0];
            }    
        );
        
        vector<vector<int> > sol;
        
        int s = intervals[0][0], e = intervals[0][1];
        
        int i = 1;
        while(i < n) {
            if(intervals[i][0] <= e) {
                e = max(e, intervals[i][1]);
            } else {
                vector<int> v = {s, e};
                sol.push_back(v);
                
                s = intervals[i][0];
                e = intervals[i][1];
            }
            i++;
        }
        
        vector<int> v = {s, e};
        sol.push_back(v);
        
        return sol;
    }
};