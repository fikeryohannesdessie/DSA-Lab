class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        vector<vector<int>> H(M, vector<int>(N, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 1) { // BFS from the water cells.
                    q.emplace(i, j);
                    H[i][j] = 0;
                }
            }
        }
        int h = 0, dirs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy]: dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || a >= M || b < 0 || b >= N || H[a][b] != -1) continue;
                    H[a][b] = h + 1;
                    q.emplace(a, b);
                }
            }
            ++h;
        }
        return H;
    }
};