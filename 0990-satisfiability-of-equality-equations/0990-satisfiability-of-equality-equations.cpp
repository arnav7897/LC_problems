class Solution {
public:

    bool equationsPossible(vector<string>& e) {

        unordered_map<char, vector<char>> mp;

        for (auto &s : e) {
            if (s[1] == '=') {
                char a = s[0];
                char b = s[3];

                mp[a].push_back(b);
                mp[b].push_back(a);
            }
        }

        for (auto &s : e) {

            if (s[1] == '!') {

                char start = s[0];
                char target = s[3];

                unordered_set<char> visited;
                queue<char> q;

                q.push(start);
                visited.insert(start);

                while (!q.empty()) {

                    char curr = q.front();
                    q.pop();

                    if (curr == target)
                        return false;

                    for (char next : mp[curr]) {

                        if (!visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
        }

        return true;
    }
};