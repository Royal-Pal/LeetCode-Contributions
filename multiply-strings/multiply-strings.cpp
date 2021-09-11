class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length(), m = num2.length();
        
        string res(n + m, '0');
        
        for(int i = n - 1; i >= 0; i--) {
            int carry = 0;
            
            for(int j = m - 1; j >= 0; j--) {
                int tmp = (res[i + j + 1] - '0') + 
                    ((num1[i] - '0') * (num2[j] - '0')) + carry;
                res[i + j + 1] = (tmp % 10) + '0';
                carry = tmp / 10;
            }
            
            res[i] += carry;
        }
        
        for(int i = 0; i < n + m; i++) {
            if(res[i] != '0') {
                return res.substr(i);
            }
        }
        
        return "0";
    }
};