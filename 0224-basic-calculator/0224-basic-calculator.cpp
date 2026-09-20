class Solution {
public:
    int calculate(string s) {
        stack<long long> st;

        long long res = 0;
        long long sign = 1;
        long long num = 0;

        for (auto &ch : s) {

            if (ch >= '0' && ch <= '9') {
                num = num * 10 + (ch - '0');
            }

            else if (ch == ' ') {
                continue;
            }

            else if (ch == '+') {
                res += num * sign;
                sign = 1;
                num = 0;
            }

            else if (ch == '-') {
                res += num * sign;
                sign = -1;
                num = 0;
            }

            else if (ch == '(') {
                st.push(res);
                st.push(sign);

                res = 0;
                sign = 1;
                num = 0;
            }

            else if (ch == ')') {
                res += num * sign;
                num = 0;

                long long s = st.top();
                st.pop();

                long long n = st.top();
                st.pop();

                res = n + s * res;
            }
        }

        res += num * sign;

        return (int)res;
    }
};