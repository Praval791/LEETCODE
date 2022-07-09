// ! Date :- 09-07-2022

// * https://leetcode.com/problems/jump-game-iii/

// BFS
class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        if (arr[start] == 0)
            return true;
        if (start >= arr.size() || start < 0)
            return false;
        int n = arr.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(start);

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int curr = q.front();
                q.pop();
                vis[curr] = true;
                if (arr[curr] == 0)
                    return true;
                if (arr[curr] + curr < n && !vis[arr[curr] + curr])
                    q.push(arr[curr] + curr);
                if (curr - arr[curr] > -1 && !vis[curr - arr[curr]])
                    q.push(curr - arr[curr]);
            }
        }
        return false;
    }
};

// recursion DFS
class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        if (start >= 0 && start < n && arr[start] >= 0)
        {
            if (arr[start] == 0)
                return true;
            arr[start] = -arr[start]; // mark visited
            return canReach(arr, start - arr[start]) or canReach(arr, start + arr[start]);
        }
        return false;
    }
};