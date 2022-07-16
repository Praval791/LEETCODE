// ! Date :- 15-07-2022

// * https://leetcode.com/problems/max-area-of-island/

class Solution
{
    vector<vector<int>> grid;
    int dfs(int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        return 1 + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        this->grid = grid;
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(i, j));
        return ans;
    }
};