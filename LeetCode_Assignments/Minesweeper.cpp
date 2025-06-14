class Solution {
public:
    int rows, cols;
    vector<vector<char>> board;

    vector<pair<int,int>> directions = {
        {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}
    };

    int countMines(int r, int c) {
        int count = 0;
        for (auto& d : directions) {
            int nr = r + d.first, nc = c + d.second;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'M') {
                count++;
            }
        }
        return count;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& b, vector<int>& click) {
        board = b;
        rows = board.size();
        cols = board[0].size();

        int r = click[0], c = click[1];
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        queue<pair<int,int>> q;
        q.push({r,c});
        board[r][c] = 'B';

        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            int mines = countMines(x, y);

            if (mines > 0) {
                board[x][y] = '0' + mines;
            } else {
                for (auto& d : directions) {
                    int nx = x + d.first, ny = y + d.second;
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && board[nx][ny] == 'E') {
                        board[nx][ny] = 'B';
                        q.push({nx, ny});
                    }
                }
            }
        }

        return board;
    }
};
