// ! Date :- 12-07-2022

// * https://leetcode.com/problems/distinct-subsequences/

// Brute Force (Recursion) :- TLE
class Solution
{
    string s, t;
    int sn, tn;
    int util(int strIndex, int patIndex)
    {
        if (patIndex == tn)
            return 1;
        if (strIndex == sn)
            return 0;

        if (s[strIndex] == t[patIndex])
            return util(strIndex + 1, patIndex + 1) + util(strIndex + 1, patIndex);
        return util(strIndex + 1, patIndex);
    }

public:
    int numDistinct(string s, string t)
    {
        if (t.size() > s.size())
            return 0;
        int ans = util(0, 0);
        this->s = s;
        this->t = t;
        this->sn = s.size();
        this->tn = t.size();
        return util(0, 0);
    }
};

// DP Memoization
class Solution
{
    string s, t;
    int sn, tn;
    vector<vector<int>> dp;
    int util(int strIndex, int patIndex)
    {
        if (patIndex == tn)
            return 1;
        if (strIndex == sn)
            return 0;

        if (dp[strIndex][patIndex] != -1)
            return dp[strIndex][patIndex];

        if (s[strIndex] == t[patIndex])
            return dp[strIndex][patIndex] = util(strIndex + 1, patIndex + 1) + util(strIndex + 1, patIndex);
        return dp[strIndex][patIndex] = util(strIndex + 1, patIndex);
    }

public:
    int numDistinct(string s, string t)
    {
        if (t.size() > s.size())
            return 0;
        int ans = util(0, 0);
        this->s = s;
        this->t = t;
        this->sn = s.size();
        this->tn = t.size();
        dp.resize(sn + 1, vector<int>(tn + 1, -1));
        return util(0, 0);
    }
};