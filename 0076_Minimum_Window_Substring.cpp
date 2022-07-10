// ! Date :- 10-07-2022

// * https://leetcode.com/problems/minimum-window-substring/

// ! TC :- O(M+N)
// ! SC :- O(2*N)
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int sn = s.length();
        int tn = t.length();
        if (tn > sn || sn == 0 || tn == 0)
            return "";

        // initialize hash for t
        vector<int> hash(256, 0);
        for (const char &c : t)
            hash[c]++;

        // hash for elements in current window
        vector<int> windowEle(256, 0);

        int count = 0;

        int start = 0, leftMost = -1, minLen = INT_MAX;

        for (int j = 0; j < sn; j++)
        {
            // include the element in current window
            windowEle[s[j]]++;

            // if current element is present in also hash then increase count
            if (windowEle[s[j]] <= hash[s[j]])
                count++;

            // if we find all element in current window
            if (count == tn)
            {
                // try to minimize the size of window
                // remove element from start if we don't require that element
                // either the element has count more then required or is not present in hash
                while (windowEle[s[start]] > hash[s[start]] || hash[s[start]] == 0)
                {
                    if (windowEle[s[start]] > hash[s[start]])
                        --windowEle[s[start]];
                    start++; // increament the start to check for next index
                }
                // change the values accordingly
                if (minLen > j - start + 1)
                {
                    minLen = j - start + 1;
                    leftMost = start;
                }
            }
        }

        return leftMost == -1 ? "" : s.substr(leftMost, minLen);
    }
};

// ! TC :- O(M+N)
// ! SC :- O(N)
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int sn = s.length();
        int tn = t.length();
        if (tn > sn || sn == 0 || tn == 0)
            return "";

        vector<int> hash(256, 0);
        int distinctEle = 0;
        int minLen = INT_MAX;
        int leftMost = -1;

        for (const char &c : t)
        {
            if (hash[c] == 0)
                distinctEle++;
            hash[c]++;
        }

        int left = 0;
        for (int right = 0; right < sn; right++)
        {
            if (--hash[s[right]] == 0)
                --distinctEle;

            if (distinctEle == 0)
            {
                while (distinctEle == 0)
                {
                    if (minLen > right - left + 1)
                    {
                        minLen = right - left + 1;
                        leftMost = left;
                    }
                    if (++hash[s[left]] > 0)
                        distinctEle++;
                    left++;
                }
            }
        }
        return leftMost == -1 ? "" : s.substr(leftMost, minLen);
    }
};

// ! TC :- O(M+N)
// ! SC :- O(N)
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int sn = s.length();
        int tn = t.length();
        if (tn > sn || sn == 0 || tn == 0)
            return "";
        vector<int> hash(256, 0);

        for (const char &c : t)
            hash[c]++;

        int j = 0;
        // take a window left, size of window of maximum possible size
        int ans[2] = {-1,
                      sn + 1};
        int required = tn;
        for (int i = 0; i < sn; i++)
        {
            if (hash[s[i]]-- > 0)
                --required;
            while (hash[s[j]] < 0)
                ++hash[s[j++]];
            if (required == 0 && i - j + 1 < ans[1])
            {
                ans[0] = j;
                ans[1] = i - j + 1;
            }
        }
        return (ans[0] == -1) ? "" : s.substr(ans[0], ans[1]);
    }
};