// ! Date :- 09-07-2022

// * https://leetcode.com/problems/jump-game-vii/

// Brute Force (Recursion) :- Memory Limit Exceed
class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump, int currInd = 0)
    {
        if (currInd == s.length() - 1)
            return true;

        for (int i = minJump; i <= maxJump && i < s.length(); i++)
            if (s[i + currInd] == '0' and canReach(s, minJump, maxJump, i + currInd))
                return true;
        return false;
    }
};

// DP Memoization :- Memory Limit Exceed
// ! here i try to use original to previously calculated results
class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump, int currInd = 0)
    {
        if (currInd == s.length() - 1)
            return true;
        if (s[currInd] == 't')
            return true;
        if (s[currInd] == 'f')
            return false;

        for (int i = minJump; i <= maxJump && i < s.length(); i++)
            if (s[i + currInd] == '0' and canReach(s, minJump, maxJump, i + currInd))
            {
                s[currInd] = 't';
                return true;
            }
        s[currInd] = 'f';
        return false;
    }
};

// Accepted
class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.size();
        if (s[n - 1] == '1')
            return false;
        s[0] = 'r';
        // to keep track of how far we have successfully reached and done the marking
        int lastMarked = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != 'r')
                continue;
            // we always want to mark them which are not marked yet that's why we start our minJp with max(lastMarked + 1, i + minJump)
            int minJp = max(lastMarked + 1, i + minJump);
            int maxJp = min(n - 1, i + maxJump);
            for (int i = minJp; i <= maxJp; i++)
                if (s[i] == '0')
                    s[i] = 'r';
            // Now change the value of how far marked(lastMarked)
            lastMarked = maxJp;
        }
        return s[n - 1] == 'r';
    }
};