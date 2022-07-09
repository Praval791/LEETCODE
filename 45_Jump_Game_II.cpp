// ! Date :- 09-07-2022

// * https://leetcode.com/problems/jump-game-ii/

// Naive approach (recursion) :- TLE
class Solution
{
    long int util(int currInd, vector<int> &nums, int n)
    {
        if (currInd >= n - 1)
            return 0;
        long int ans = INT_MAX;
        for (int i = 1; i <= nums[currInd]; i++)
        {
            ans = min(ans, 1 + util(currInd + i, nums, n));
        }
        return ans;
    }

public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;
        if (nums[0] == 0)
            return 0;
        return util(0, nums, n);
    }
};

// DP Memoization
// ! TC :- O(N²)
// ! SC :- O(N)
class Solution
{
    vector<int> dp;
    long int util(int currInd, vector<int> &nums, int n)
    {
        if (currInd >= n - 1)
            return 0;
        if (dp[currInd] != -1)
            return dp[currInd];
        long int ans = INT_MAX;
        for (int i = 1; i <= nums[currInd]; i++)
        {
            ans = min(ans, 1 + util(currInd + i, nums, n));
        }
        return dp[currInd] = ans;
    }

public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;
        if (nums[0] == 0)
            return 0;
        dp.resize(n, -1);
        return util(0, nums, n);
    }
};

// DP Tabulation
// ! TC :- O(N²)
// ! SC :- O(N)
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;
        if (nums[0] == 0)
            return 0;
        vector<long int> dp(n, INT_MAX);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = 1; j <= nums[i]; j++)
            {
                if (i + j < n)
                    dp[i] = min(dp[i], 1 + dp[i + j]);
            }
        }
        return dp[0];
    }
};

// ! TC :- O(N)
// ! SC :- O(1)
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;
        if (nums[0] == 0)
            return 0;
        int jumps = 1;
        int steps = nums[0];
        int maxReach = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                return jumps;
            maxReach = max(maxReach, nums[i] + i);
            steps--;
            if (steps <= 0)
            {
                jumps++;
                if (i >= maxReach)
                    break;
                steps = maxReach - i;
            }
        }
        return -1;
    }
};
