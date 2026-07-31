class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> need, window;

        for (char c : s1)
            need[c]++;

        int k = s1.size();

        for (int i = 0; i < k; i++)
            window[s2[i]]++;

        if (window == need)
            return true;

        for (int i = k; i < s2.size(); i++) {
            window[s2[i]]++;

            window[s2[i - k]]--;
            if (window[s2[i - k]] == 0)
                window.erase(s2[i - k]);

            if (window == need)
                return true;
        }

        return false;
    }
};
