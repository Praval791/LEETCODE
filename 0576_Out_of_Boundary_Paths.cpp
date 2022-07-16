// ! Date :- 16-07-2022

// * https://leetcode.com/problems/out-of-boundary-paths/

// Brute force (recursion) :- TLE
class Solution
{
    const int modulo = 1000000007;

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if (startRow < 0 || startColumn < 0 || startColumn == n || startRow == m)
            return 1;
        if (!maxMove)
            return 0;
        return (((findPaths(m, n, maxMove - 1, startRow - 1, startColumn) % modulo +
                  findPaths(m, n, maxMove - 1, startRow + 1, startColumn) % modulo) %
                     modulo +
                 findPaths(m, n, maxMove - 1, startRow, startColumn + 1) % modulo) %
                    modulo +
                findPaths(m, n, maxMove - 1, startRow, startColumn - 1) % modulo) %
               modulo;
    }
};

// DP Memoization
class Solution
{
    const int modulo = 1000000007;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>> &dp)
    {
        if (startRow < 0 || startColumn < 0 || startColumn == n || startRow == m)
            return 1;
        if (!maxMove)
            return 0;
        if (dp[startRow][startColumn][maxMove] != -1)
            return dp[startRow][startColumn][maxMove];
        dp[startRow][startColumn][maxMove] = (((findPaths(m, n, maxMove - 1, startRow - 1, startColumn, dp) % modulo +
                                                findPaths(m, n, maxMove - 1, startRow + 1, startColumn, dp) % modulo) %
                                                   modulo +
                                               findPaths(m, n, maxMove - 1, startRow, startColumn + 1, dp) % modulo) %
                                                  modulo +
                                              findPaths(m, n, maxMove - 1, startRow, startColumn - 1, dp) % modulo) %
                                             modulo;
        return dp[startRow][startColumn][maxMove];
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return findPaths(m, n, maxMove, startRow, startColumn, dp);
    }
};

// DP Tabulation
class Solution
{
public:
    const int modulo = 1000000007;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if (maxMove == 0)
            return 0;

        // dp[i][j][k] stores the total number of ways to cross out the boundaries in maximum k number of moves if we are at i,j position.
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, 0)));
        // fill the boundaries because we only need 1 step to cross the boundary and since we have to count all possibilities that's why we add +1 (there is another one way to cross the boundary).
        // fill 1st column and last column of each row
        for (int i = 0; i < m; i++)
        {
            dp[i][0][1] += 1;
            dp[i][n - 1][1] += 1;
        }
        // fill 1st row and last row of each column
        for (int i = 0; i < n; i++)
        {
            dp[0][i][1] += 1;
            dp[m - 1][i][1] += 1;
        }

        for (int k = 2; k <= maxMove; k++)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    // if we can move down
                    if (i + 1 < m)
                        dp[i][j][k] = (dp[i][j][k] + dp[i + 1][j][k - 1]) % modulo;
                    // if we can move up
                    if (i - 1 >= 0)
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % modulo;
                    // if we can move right
                    if (j + 1 < n)
                        dp[i][j][k] = (dp[i][j][k] + dp[i][j + 1][k - 1]) % modulo;
                    // if we can move left
                    if (j - 1 >= 0)
                        dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k - 1]) % modulo;
                }
            }
        }
        // numer of ways to cross the boundary if we are at (startRow,startColumn) position in maximum k moves;
        long int sum = 0;
        for (int k = 1; k <= maxMove; k++)
            sum = (sum + dp[startRow][startColumn][k]) % modulo;
        return sum;
    }
};
