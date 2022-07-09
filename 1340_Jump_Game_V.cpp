// ! Date :- 09-07-2022

// * https://leetcode.com/problems/jump-game-v/

// DP (Memoization)
class Solution
{
public:
    int f(vector<int> &arr, vector<int> &dp, int d, int &i, int n)
    {
        // initially we are standing at positon 1 so ans=1 initially
        int ans = 1;
        if (dp[i] != 0)
            return dp[i];
        // move till d distance in forward and backward direction, if you find any building height > current height then stop
        for (int j = i + 1; j <= min(i + d, n - 1) && arr[i] > arr[j]; j++)
            ans = max(ans, 1 + f(arr, dp, d, j, n));
        for (int j = i - 1; j >= max(i - d, 0) && arr[i] > arr[j]; j--)
            ans = max(ans, 1 + f(arr, dp, d, j, n));

        // store max of ans we get from moving to left and right at distance k of index i
        return dp[i] = ans;
    }
    int maxJumps(vector<int> &arr, int d)
    {
        int n = arr.size(), ans = 1;
        vector<int> dp(1005, 0);
        // traversing every index
        for (int i = 0; i < n; ++i)
            ans = max(ans, f(arr, dp, d, i, n));
        return ans;
    }
};