// Max connected island size using floodfill


class Solution {
    int dfs(int r, int c, vector<vector<int>>& g) {
        if (r < 0 || c < 0 || r >= g.size() || c >= g[0].size() || g[r][c] == 0)
            return 0;
        g[r][c] = 0;
        return 1 + dfs(r+1,c,g)+dfs(r-1,c,g)+dfs(r,c+1,g)+dfs(r,c-1,g);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int best = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j])
                    best = max(best, dfs(i, j, grid));
        return best;
    }
};
