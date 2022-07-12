// ! Date :- 12-07-2022

// * https://leetcode.com/problems/matchsticks-to-square/

// Brute force (BackTracking) :- TLE
class Solution
{
    bool dfs(int index, vector<int> &sides, int &target, vector<int> &matchsticks)
    {
        if (index == matchsticks.size())
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;

        int ans = false;
        for (int i = 0; i < 4; i++)
        {
            sides[i] += matchsticks[index];
            if (sides[i] <= target)
                ans = ans or dfs(index + 1, sides, target, matchsticks);
            sides[i] -= matchsticks[index];
        }

        return ans;
    }

public:
    bool makesquare(vector<int> &matchsticks)
    {
        int sum = 0;
        int n = matchsticks.size();
        sum = accumulate(matchsticks.begin(), matchsticks.end(), sum);
        sort(matchsticks.begin(), matchsticks.end());
        if (n < 4 || sum % 4 != 0 || matchsticks[n - 1] > sum / 4)
            return false;
        vector<int> sides(4, 0);
        int target = sum / 4;
        return dfs(0, sides, target, matchsticks);
    }
};

// Accepted but high Time complexity
class Solution
{
    int dp[4] = {0};
    bool dfs(int index, vector<int> &sides, int &target, vector<bool> &visited, vector<int> &matchsticks)
    {
        if (index == matchsticks.size())
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;

        for (int i = 0; i < 4; i++)

            if (sides[i] + matchsticks[index] <= target)
            {

                // here we check that if for any of previously checked side (side[j]) has equal length then current side (side[i]) then we don't have to check for side[i] because if for side[j] we don't find answer true then there is no way we find for current side[i] since they both have same length.
                // [Note :- How do we got to know that we don't find answer for side j because if we find true for that side[j] then we had already returned true and we don't come to this step and have to check for this side]
                int j = i;
                while (--j >= 0)
                    if (sides[i] == sides[j])
                        break;
                if (j != -1)
                    continue;

                sides[i] += matchsticks[index];
                if (dfs(index + 1, sides, target, matchsticks))
                    return true;
                sides[i] -= matchsticks[index];
            }

        return false;
    }

public:
    bool makesquare(vector<int> &matchsticks)
    {
        int sum = 0;
        int n = matchsticks.size();
        sum = accumulate(matchsticks.begin(), matchsticks.end(), sum);
        sort(matchsticks.begin(), matchsticks.end());
        if (n < 4 || sum % 4 != 0 || matchsticks[n - 1] > sum / 4)
            return false;
        vector<int> sides(4, 0);
        vector<bool> visited(n + 1, false);
        int target = sum / 4;
        return dfs(0, sides, target, , visited, matchsticks);
    }
};

// Optimized DP
class Solution
{
    bool dfs(int index, int currSideSum, int remainingSides, int &target, vector<bool> &visited, vector<int> &matchsticks)
    {
        if (remainingSides == 0)
            return true;
        if (currSideSum == target)
            return dfs(0, 0, remainingSides - 1, target, visited, matchsticks);

        for (int j = index; j < matchsticks.size(); j++)
        {
            // matchsticks[j-1] is not visited means in previous iteration we not get true return
            // Since matchsticks[j] == matchsticks[j-1] , there is no need to check again for same value
            if (visited[j] || currSideSum + matchsticks[j] > target || (j > 0 && matchsticks[j] == matchsticks[j - 1] && !visited[j - 1]))
                continue;

            visited[j] = true;
            if (dfs(j + 1, currSideSum + matchsticks[j], remainingSides, target, visited, matchsticks))
                return true;
            visited[j] = false;
        }

        return false;
    }

public:
    bool makesquare(vector<int> &matchsticks)
    {
        int sum = 0;
        int n = matchsticks.size();
        sum = accumulate(matchsticks.begin(), matchsticks.end(), sum);
        sort(matchsticks.begin(), matchsticks.end());
        if (n < 4 || sum % 4 != 0 || matchsticks[n - 1] > sum / 4)
            return false;
        int target = sum / 4;
        int remainingSides = 4;
        int currSideSum = 0;
        vector<bool> visited(n, false);
        return dfs(0, currSideSum, remainingSides, target, visited, matchsticks);
    }
};
