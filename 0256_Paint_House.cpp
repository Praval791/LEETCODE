// ! Date :- 08-07-2022

// * https://leetcode.com/problems/paint-house/
// * https://www.interviewbit.com/problems/paint-house/

// * Problem description :- Given an 2D array cost[N][3], where cost[i][0], cost[i][1], and cost[i][2] is the cost of painting ith house with colors red, blue, and green respectively, the task is to find the minimum cost to paint all the houses such that no two adjacent houses have the same color.

#include <bits/stdc++.h>
using namespace std;

// DP Tabulation
class Solution1
{
public:
    int paintHouse(vector<vector<int>> &costs)
    {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        // if first house is colored with color 1 then next house can be colored with other 2 colors
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i][2];
        }
        return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }
};

// DP Memoization
class Solution2
{
    vector<vector<int>> dp;
    int n;
    int util(int houseInd, int colorInd, vector<vector<int>> &costs)
    {
        if (houseInd == n)
            return 0;
        if (dp[houseInd][colorInd] != -1)
            return dp[houseInd][colorInd];
        int temp = INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            if (i != colorInd)
                temp = min(temp, util(houseInd + 1, i, costs));
        }
        return dp[houseInd][colorInd] = costs[houseInd][colorInd] + temp;
    }

public:
    int paintHouse(vector<vector<int>> &costs)
    {
        this->n = costs.size();
        dp.resize(n, vector<int>(3, -1));
        return min(min(util(0, 0, costs), util(0, 1, costs)), util(0, 2, costs));
    }
};

// Driver code
int main()
{
    Solution1 obj;
    vector<vector<int>> costs{
        {774, 271, 764}, {669, 193, 986}, {103, 481, 214}, {628, 803, 100}, {528, 626, 544}, {925, 24, 973}, {62, 182, 4}, {433, 506, 594}, {726, 32, 493}, {143, 223, 287}, {65, 901, 188}, {361, 414, 975}, {271, 171, 236}, {834, 712, 761}, {897, 668, 286}, {551, 141, 695}, {696, 625, 20}, {126, 577, 695}, {659, 303, 372}, {467, 679, 594}, {852, 485, 19}, {465, 120, 153}, {801, 88, 61}, {927, 11, 758}, {171, 316, 577}, {228, 44, 759}, {165, 110, 883}, {87, 566, 488}, {578, 475, 626}, {628, 630, 929}, {424, 521, 903}, {963, 124, 597}, {738, 262, 196}, {526, 265, 261}, {203, 117, 31}, {327, 12, 772}, {412, 548, 154}};
    cout << obj.paintHouse(costs);

    return 0;
}
