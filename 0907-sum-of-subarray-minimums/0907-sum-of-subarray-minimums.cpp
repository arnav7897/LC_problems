class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                left[i] = i - st.top() - 1;
            } else {
                left[i] = i;
            }

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                right[i] = st.top() - i - 1;
            } else {
                right[i] = n - i - 1;
            }

            st.push(i);
        }


        int mod = 1e9 + 7;
        long long res = 0;
    for (int i = 0; i < n; i++) {
        long long contribution =
            ((1LL * arr[i])%mod +
            (1LL * left[i] * arr[i])%mod +
            (1LL * right[i] * arr[i])%mod +
            (1LL * left[i] * right[i] * arr[i])%mod)%mod;

        res = (res + contribution) % mod;
}

        return res;
    }
};