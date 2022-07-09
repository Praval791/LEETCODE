// ! Date :- 08-07-2022

// * https://leetcode.com/problems/interleaving-string

// DP(Tabulation)
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3)
            return false;
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        for (int i = n1; i >= 0; --i)
            for (int j = n2; j >= 0; --j)
                if (i == n1 && j == n2)
                    dp[i][j] = true;
                else
                {
                    if (s1[i] == s3[i + j])
                        dp[i][j] = dp[i + 1][j];
                    if (s2[j] == s3[i + j])
                        dp[i][j] = dp[i][j] || dp[i][j + 1];
                }
        return dp[0][0];
    }
};

// REC with MEMO == DP(Memoization)
class Solution
{
    bool rec(string s1, string s2, string s3, int i, int j, vector<vector<int>> &dp)
    {
        if (i == s1.size() && j == s2.size())
            return true;
        if (i > s1.size() || j > s2.size())
            return false;
        if (dp[i][j] != -1)
            return dp[i][j];

        if ((s3[i + j] == s2[j] && rec(s1, s2, s3, i, j + 1, dp)) or (s3[i + j] == s1[i] && rec(s1, s2, s3, i + 1, j, dp)))
            return dp[i][j] = true;

        return dp[i][j] = false;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;
        vector<vector<int>> dp(s1.size() + 1, (vector<int>(s2.size() + 1, -1)));
        return rec(s1, s2, s3, 0, 0, dp);
    }
};

// TLE
class Solution
{
    bool isInterleave(string s1, string s2, string s3, int i1, int i2, int i3)
    {
        if (i1 == s1.length() and i2 == s2.length())
            return true;
        if (s1[i1] == s3[i3] and i1 <= s1.length() and isInterleave(s1, s2, s3, i1 + 1, i2, i3 + 1))
            return true;
        if (s2[i2] == s3[i3] and i2 <= s2.length() and isInterleave(s1, s2, s3, i1, i2 + 1, i3 + 1))
            return true;
        return false;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;
        return isInterleave(s1, s2, s3, 0, 0, 0);
    }
};
