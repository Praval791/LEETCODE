// ! Date :- 07-07-2022

// * https://leetcode.com/problems/unique-binary-search-trees/

// 1. Brute force (recursion without memoization) :- TLE
class Solution
{
public:
    int numTrees(int n)
    {
        if (n <= 1)
            return 1;
        if (n == 2)
            return 2;
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += (numTrees(n - i) * numTrees(i - 1));
        return ans;
    }
};

// DP solution (recursion with memoization) :- Accepted 100% fast
class Solution
{
    int memo[20] = {0};

public:
    int numTrees(int n)
    {
        if (n <= 1)
            return 1;
        if (n == 2)
            return 2;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (memo[i - 1] == 0)
                memo[i - 1] = numTrees(i - 1);
            if (memo[n - i] == 0)
                memo[n - i] = numTrees(n - i);
            ans += memo[i - 1] * memo[n - i];
        }
        return memo[n] = ans;
    }
};
