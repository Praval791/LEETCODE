// ! Date :- 09-07-2022

// * https://leetcode.com/problems/jump-game-iv/

// BFS 1
// Here i use visited array to store the result
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        // int ans = 0;
        // value and index
        int n = arr.size();
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < n; i++)
        {
            if (hash.find(arr[i]) == hash.end())
                hash[arr[i]] = {i};
            else
                hash[arr[i]].push_back(i);
        }
        // initialize visited array with maximum value possible to reach the end when all elements are different
        vector<int> visited(n, n);
        visited[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int currPosition = q.front();
                q.pop();
                if (currPosition == n - 1)
                    return visited[n - 1];
                vector<int> indeces = hash[arr[currPosition]];
                for (int ind : indeces)
                    if (ind != currPosition)
                        if (visited[currPosition] + 1 < visited[ind])
                        {
                            visited[ind] = visited[currPosition] + 1;
                            q.push(ind);
                        }
                hash.erase(arr[currPosition]);
                if (currPosition + 1 < n)
                {
                    if (visited[currPosition] + 1 < visited[currPosition + 1])
                    {
                        visited[currPosition + 1] = visited[currPosition] + 1;
                        q.push(currPosition + 1);
                    }
                }
                if (currPosition - 1 >= 0)
                {
                    if (visited[currPosition] + 1 < visited[currPosition - 1])
                    {
                        visited[currPosition - 1] = visited[currPosition] + 1;
                        q.push(currPosition - 1);
                    }
                }
            }
        }
        return -1;
    }
};

// BFS 2
// Here steps variables is used to keep track of the steps taken so far to reach that index
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int ans = 0;
        // value and index
        int n = arr.size();
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < n; i++)
        {
            if (hash.find(arr[i]) == hash.end())
                hash[arr[i]] = {i};
            else
                hash[arr[i]].push_back(i);
        }
        vector<bool> visited(n, false);
        visited[0] = true;
        int steps = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int size = q.size();
            // iterate the layer
            while (size--)
            {
                int currPosition = q.front();
                q.pop();
                if (currPosition == n - 1)
                    return steps;
                vector<int> indeces = hash[arr[currPosition]];
                for (int ind : indeces)
                    if (ind != currPosition && !visited[ind])
                    {
                        visited[ind] = true;
                        q.push(ind);
                    }
                hash.erase(arr[currPosition]);
                if (currPosition + 1 < n && !visited[currPosition + 1])
                {
                    visited[currPosition + 1] = true;
                    q.push(currPosition + 1);
                }
                if (currPosition - 1 >= 0 && !visited[currPosition - 1])
                {
                    visited[currPosition - 1] = true;
                    q.push(currPosition - 1);
                }
                // set<int, greater<int> > indeces = hash[arr[currPosition]];
            }
            steps++;
        }
        return ans;
    }
};
