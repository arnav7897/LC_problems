class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;
        int n = s.size();
        int i = 0;

        while (i < n) {
            // Skip '/'
            while (i < n && s[i] == '/') {
                i++;
            }

            if (i >= n) break;

            // Extract one component
            string curr;

            while (i < n && s[i] != '/') {
                curr += s[i];
                i++;
            }

            if (curr == ".") {
                continue;
            }
            else if (curr == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(curr);
            }
        }

        if (st.empty()) {
            return "/";
        }

        string ans;
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};