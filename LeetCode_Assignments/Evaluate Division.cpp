class Solution {
public:
    // Create a graph using unordered_map
    unordered_map<string, vector<pair<string, double>>> graph;

    void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            // Adding edges in both directions
            graph[u].push_back({v, val});
            graph[v].push_back({u, 1.0 / val});
        }
    }

    double bfs(string start, string end) {
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
            return -1.0;

        queue<pair<string, double>> q;
        unordered_set<string> visited;

        q.push({start, 1.0});
        visited.insert(start);

        while (!q.empty()) {
            auto [node, prod] = q.front();
            q.pop();

            if (node == end)
                return prod;

            for (auto& [neighbor, weight] : graph[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push({neighbor, prod * weight});
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        buildGraph(equations, values);
        vector<double> result;

        for (auto& q : queries) {
            result.push_back(bfs(q[0], q[1]));
        }

        return result;
    }
};
