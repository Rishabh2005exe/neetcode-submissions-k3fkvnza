
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;

        // Add all unique characters
        for (auto &word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string &w1 = words[i];
            string &w2 = words[i + 1];

            // Invalid case
            if (w1.size() > w2.size() &&
                w1.substr(0, w2.size()) == w2)
                return "";

            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    break;
                }
            }
        }

        // Kahn's Algorithm
        queue<char> q;
        for (auto &it : indegree) {
            if (it.second == 0)
                q.push(it.first);
        }

        string ans;

        while (!q.empty()) {
            char curr = q.front();
            q.pop();

            ans += curr;

            for (char nei : graph[curr]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // Cycle exists
        if (ans.size() != indegree.size())
            return "";

        return ans;
    }
};