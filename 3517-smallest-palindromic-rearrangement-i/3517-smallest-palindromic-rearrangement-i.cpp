class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> f(26, 0);
        for (char c : s)
            f[c - 'a']++;
        string left = "";
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            left.append(f[i] / 2, char(i + 'a'));

            if (f[i] % 2 == 1){
                mid = char(i + 'a');
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid){
            left.push_back(mid);
        }

        return left + right;
    }
};
