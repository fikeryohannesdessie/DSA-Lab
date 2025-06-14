class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // Mark entrance as visited

        int steps = 0;
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty()) {
            int size = q.size();
            steps++;

            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front(); q.pop();

                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;

                    // Check if valid and not visited
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] == '.') {
                        // Check if it's on the boundary and not the entrance
                        if (nx == 0 || ny == 0 || nx == rows - 1 || ny == cols - 1) {
                            return steps;
                        }

                        // Mark as visited and push to queue
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
        }

        return -1; // No exitfound
    }
};
