// ! Date :- 14-07-2022

// * https://leetcode.com/problems/longest-common-subsequence/

// DP (Memoization) :- TLE
class Solution
{
    vector<vector<int>> dp;
    int dpUtil(int i, int j, string text1, string text2)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)

            return dp[i][j];
        if (text1[i] == text2[j])

            return dp[i][j] = 1 + dpUtil(i - 1, j - 1, text1, text2);

        return dp[i][j] = max(dpUtil(i - 1, j, text1, text2), dpUtil(i, j - 1, text1, text2));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        dp.resize(text1.length() + 1, vector<int>(text2.length() + 1, -1));
        return dpUtil(text1.length() - 1, text2.length() - 1, text1, text2);
    }
};

// DP Tabulation

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.length(), n2 = text2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if (text1[i] == text2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[n1][n2];
    }
};