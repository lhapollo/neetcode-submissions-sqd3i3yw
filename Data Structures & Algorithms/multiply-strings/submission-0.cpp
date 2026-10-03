class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        if (num1.size() < num2.size()) return multiply(num2, num1);

        string res = "";
        int zero = 0;
        for (int i = num2.size() - 1; i >= 0; i--) {
            string cur = mul(num1, num2[i], zero);
            res = add(res, cur);
            zero++;
        }
        return res; 
    }

    string mul(string s, char d, int zero) {
        int i = s.size()-1; 
        int digit = d - '0';
        int carry = 0;
        string cur; 

        while (i >= 0 || carry) {
            int n = (i >= 0) ? s[i] - '0': 0;
            int prod = n * digit + carry; 
            cur.push_back((prod % 10) + '0');
            carry = prod / 10;
            i --;
        }

        reverse(cur.begin(), cur.end());
        return cur + string(zero, '0');
    }

    string add(string num1, string num2) {
        int n = num1.length() - 1;
        int m = num2.length() - 1;
        int carry = 0;
        string ans = "";
        while (n >= 0 || m >= 0 || carry) {
            int d1 = (n >= 0) ? num1[n] - '0' : 0;
            int d2 = (m >= 0) ? num2[m] - '0' : 0;
            int sum = d1 + d2 + carry; 
            if (sum >= 10) {
                sum -= 10;
                carry = 1; 
            } else {
                carry = 0;
            }
            string res = to_string(sum);
            ans += res; 
            n--;
            m--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


/*
123+4567

7654
321
*/