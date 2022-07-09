// ! Date :- 09-07-2022

// * https://leetcode.com/problems/jump-game-vi/

// DP Memoization :- TLE
// ! TC :- O(N*K)
// ! SC :- O(N)
class Solution
{
    vector<int> nums;
    vector<long int> dp;
    int n, k;
    long int util(int currIndex)
    {
        if (currIndex == n - 1)
            return nums[n - 1];
        if (dp[currIndex] != INT_MIN)
            return dp[currIndex];
        long int ans = INT_MIN;
        for (int i = 1; i <= k && currIndex + i < n; i++)
            ans = max(ans, nums[currIndex] + util(i + currIndex));
        return dp[currIndex] = ans;
    }

public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        this->nums = nums;
        this->n = n;
        this->k = k;
        dp.resize(n, INT_MIN);
        int ans = util(0);
        return ans;
    }
};

// DP Tabulation :- TLE
// ! TC :- O(N*K)
// ! SC :- O(N)
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long int> dp(n, INT_MIN);
        dp[n - 1] = nums[n - 1];
        for (int currInd = n - 2; currInd >= 0; currInd--)
            for (int i = 1; i <= k && currInd + i < n; i++)
                dp[currInd] = max(dp[currInd], dp[currInd + i] + nums[currInd]);
        return dp[0];
    }
};

// DP with max Heap
// ! TC :- O(N*log(K))
// ! SC :- O(N)
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long int> dp(n);
        dp[n - 1] = nums[n - 1];
        priority_queue<pair<int, int>> pq;
        pq.push({dp[n - 1], n - 1});
        for (int currInd = n - 2; currInd >= 0; currInd--)
        {
            while (pq.size() && pq.top().second > currInd + k)
                pq.pop();
            dp[currInd] = pq.top().first + nums[currInd];
            pq.push({dp[currInd], currInd});
        }
        return dp[0];
    }
};
