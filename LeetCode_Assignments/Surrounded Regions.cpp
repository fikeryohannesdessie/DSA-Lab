class Solution {
public:
    int rows, cols;
    vector<vector<char>> board;

    void bfs(int r, int c) {
        queue<pair<int,int>> q;
        q.push({r,c});
        board[r][c] = 'S';  // Mark safe

        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop();

            for (auto& d : directions) {
                int nx = x + d.first, ny = y + d.second;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && board[nx][ny] == 'O') {
                    board[nx][ny] = 'S';
                    q.push({nx, ny});
                }
            }
        }
    }

    void solve(vector<vector<char>>& b) {
        board = b;
        rows = board.size();
        if (rows == 0) return;
        cols = board[0].size();

        // Mark all"O" connected to borders as safe
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') bfs(i, 0);
            if (board[i][cols-1] == 'O') bfs(i, cols-1);
        }
        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'O') bfs(0, j);
            if (board[rows-1][j] == 'O') bfs(rows-1, j);
        }

        // Flip all unsafe "O" to 'X', safe 'S' back to "O"
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'S')
                    board[i][j] = 'O';

        b = board;  // Copyback
    }
};
