// ! Date :- 10-07-2022

// * https://leetcode.com/problems/min-cost-climbing-stairs/

// Brute force (Recursion)
class Solution
{
public:
    int dp(vector<int> &cost, int n)
    {
        if (n < 2)
        {
            return cost[n];
        }
        return cost[n] + min(dp(cost, n - 1), dp(cost, n - 2));
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        cost.push_back(0);
        return dp(cost, cost.size() - 1);
    }
};

// DP Memoization
class Solution
{
public:
    unordered_map<int, int> memo;
    int dp(vector<int> &cost, int n)
    {
        if (n < 2)
        {
            return cost[n];
        }
        if (memo.find(n) == memo.end())
        {
            memo[n] = cost[n] + min(dp(cost, n - 1), dp(cost, n - 2));
        }
        return memo[n];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        cost.push_back(0);
        return dp(cost, cost.size() - 1);
    }
};

// DP Tabulation
// * Use cost array for storing previously calculated costs
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        for (int i = 2; i < cost.size(); i++)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};

// DP Tabulation another variant
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int lastSt = 0, secondLS = 0;
        for (int i = cost.size() - 1; i >= 0; i--)
        {
            int curr = cost[i] + min(lastSt, secondLS);
            lastSt = secondLS;
            secondLS = curr;
        }
        return min(lastSt, secondLS);
    }
};
