// ! Date :- 09-07-2022

// * https://leetcode.com/problems/jump-game/

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return true;
        if (nums[0] == 0)
            return false;
        int steps = nums[0];
        int maxReach = nums[0];
        int i;
        for (i = 0; i < nums.size(); i++)
        {
            maxReach = max(maxReach, i + nums[i]);
            steps--;
            if (steps <= 0)
            {
                if (i >= maxReach)
                    break;
                steps = maxReach - i;
            }
        }
        return i >= nums.size() - 1 ? true : false;
    }
};

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        const int n = nums.size();
        // The number of jumps needed to reach the starting index is 0
        if (n <= 1)
            return true;

        // Return -1 if not possible to jump
        if (nums[0] == 0)
            return false;

        int target = n - 1;
        for (int i = n - 2; i >= 0; --i)
            // if we can reach the target from any previous index then our next target will be that index
            if (i + nums[i] >= target)
                target = i;
        return target == 0;
    }
};