class Solution {
public:
    vector<vector<int>> graph;

    bool canDetonate(const vector<int>& a, const vector<int>& b) {
        long long dx = (long long)a[0] - b[0];
        long long dy = (long long)a[1] - b[1];
        long long r = (long long)a[2];
        return dx * dx + dy * dy <= r * r;
    }

    int bfs(int start) {
        int n = graph.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int count = 1;

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (int nei : graph[curr]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push(nei);
                    count++;
                }
            }
        }
        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        graph.resize(n);

        // build a graph if i can detonate j
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && canDetonate(bombs[i], bombs[j]))
                    graph[i].push_back(j);

        int maxDetonated = 0;
        for (int i = 0; i < n; i++)
            maxDetonated = max(maxDetonated, bfs(i));

        return maxDetonated;
    }
};
