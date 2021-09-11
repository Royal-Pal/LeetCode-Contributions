class Solution {
public:
    string addStrings(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        
        string s = "";
        
        int i = n - 1, j = m - 1, carry = 0;
        while(i >= 0 && j >= 0) {
            int n1 = s1[i] - 48;
            int n2 = s2[j] - 48;
            
            int n = n1 + n2 + carry;
            carry = n / 10;
            
            s = s + (char)((n % 10) + 48);
            
            i--;    j--;
        }
        
        while(i >= 0) {
            int n1 = s1[i] - 48;
            
            int n = n1 + carry;
            carry = n / 10;
            
            s = s + (char)((n % 10) + 48);
            
            i--;
        }
        while(j >= 0) {
            int n2 = s2[j] - 48;
            
            int n = n2 + carry;
            carry = n / 10;
            
            s = s + (char)((n % 10) + 48);
            
            j--;
        }
        
        if(carry != 0) {
            s = s + (char)(carry + 48);
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};