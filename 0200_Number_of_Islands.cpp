// ! Date :- 15-07-2022

// * https://leetcode.com/problems/number-of-islands/

class Solution
{
public:
    void BFS(vector<vector<char>> &grid, int i, int j)
    {
        // Bounding Function // boundary check
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';    // Mark as visited
        BFS(grid, i + 1, j); // Down Adjacent
        BFS(grid, i - 1, j); // Up Adjacent
        BFS(grid, i, j + 1); // Right Adjacent
        BFS(grid, i, j - 1); // Left Adjacent
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        int count = 0;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == '1')
                {
                    BFS(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
