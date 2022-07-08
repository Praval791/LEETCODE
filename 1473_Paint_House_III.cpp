// ! Date :- 08-07-2022

// * https://leetcode.com/problems/paint-house-iii/

// DP (Memoization)
class Solution
{
    int dp[101][21][101];
    int util(int houseInd, int prevHousecolor, int neighborsTillNow, vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        if (neighborsTillNow > target)
            return INT_MAX / 2;
        if (houseInd == m)
            return neighborsTillNow == target ? 0 : INT_MAX / 2;
        // If we already calculated the result
        if (dp[houseInd][prevHousecolor][neighborsTillNow] != -1)
            return dp[houseInd][prevHousecolor][neighborsTillNow];

        int ans = INT_MAX / 2;
        // if current house is not painted
        if (houses[houseInd] == 0)
        {
            // try to color with all the possible colors
            for (int colorInd = 1; colorInd <= n; colorInd++)
            {

                int newneighborsTillNow = (prevHousecolor == colorInd ? neighborsTillNow : neighborsTillNow + 1);
                ans = min(ans, cost[houseInd][colorInd - 1] + util(houseInd + 1, colorInd, newneighborsTillNow, houses, cost, m, n, target));
            }
        }
        else
        {
            int newneighborsTillNow = (prevHousecolor == houses[houseInd] ? neighborsTillNow : neighborsTillNow + 1);
            ans = min(ans, util(houseInd + 1, houses[houseInd], newneighborsTillNow, houses, cost, m, n, target));
        }
        return dp[houseInd][prevHousecolor][neighborsTillNow] = ans;
    }

public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        memset(dp, -1, sizeof(dp));
        int ans = util(0, 0, 0, houses, cost, m, n, target);
        return ans == INT_MAX / 2 ? -1 : ans;
    }
};

// Brute force (Recursion) :- TLE
class Solution
{

    int util(int houseInd, int prevHousecolor, int neighborsTillNow, vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        if (neighborsTillNow > target)
            return INT_MAX / 2;
        if (houseInd == m)
            return neighborsTillNow == target ? 0 : INT_MAX / 2;
        int ans = INT_MAX / 2;
        // if current house is not painted
        if (houses[houseInd] == 0)
        {
            // try to color with all the possible colors
            for (int colorInd = 1; colorInd <= n; colorInd++)
            {

                int newneighborsTillNow = (prevHousecolor == colorInd ? neighborsTillNow : neighborsTillNow + 1);
                ans = min(ans, cost[houseInd][colorInd - 1] + util(houseInd + 1, colorInd, newneighborsTillNow, houses, cost, m, n, target));
            }
        }
        else
        {
            int newneighborsTillNow = (prevHousecolor == houses[houseInd] ? neighborsTillNow : neighborsTillNow + 1);
            ans = min(ans, util(houseInd + 1, houses[houseInd], newneighborsTillNow, houses, cost, m, n, target));
        }
        return ans;
    }

public:
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        int ans = util(0, 0, 0, houses, cost, m, n, target);
        return ans == INT_MAX / 2 ? -1 : ans;
    }
};