class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> sf;
        unordered_map<char, int> tf;

        for (char c : t)
            tf[c]++;

        int required = tf.size();
        int formed = 0;

        int l = 0;
        int n = s.length();

        string ans = "";
        int mini = INT_MAX;
        int start = -1 , end = -1;
        for (int r = 0; r < n; r++) {

            sf[s[r]]++;

            if (tf.count(s[r]) && sf[s[r]] == tf[s[r]])
                formed++;

            while (formed == required) {
                if (r - l + 1 < mini) {
                    start = l;
                    end = r;
                    mini = r - l + 1;
                }

                sf[s[l]]--;

                if (tf.count(s[l]) && sf[s[l]] < tf[s[l]])
                    formed--;

                if (sf[s[l]] == 0)
                    sf.erase(s[l]);

                l++;
            }
        }
        if(start == -1){
            return "";
        }
        return s.substr(start , end - start + 1);
    }
};