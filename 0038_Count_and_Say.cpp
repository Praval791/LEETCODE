// ! Date :- 13-07-2022

// * https://leetcode.com/problems/count-and-say/

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string prevString = countAndSay(n - 1);
        string res;
        int countOfChar = 1;
        char prevChar = prevString[0];
        for (int i = 1; i < prevString.length(); i++)
        {
            if (prevChar == prevString[i])
                countOfChar++;
            else
            {
                res += to_string(countOfChar) + prevChar;
                countOfChar = 1;
                prevChar = prevString[i];
            }
        }
        res += to_string(countOfChar) + prevChar;
        return res;
    }
};

class Solution
{
public:
    string countAndSay(int n)
    {
        string res;
        if (n == 1)
            res = "1";
        if (n >= 2)
            res = "11";

        for (int i = 3; i <= n; i++)
        {
            string temp;
            int countOfChar = 1;
            char prevChar = res[0];
            for (int i = 1; i < res.length(); i++)
            {
                if (prevChar == res[i])
                    countOfChar++;
                else
                {
                    temp += to_string(countOfChar) + prevChar;
                    countOfChar = 1;
                    prevChar = res[i];
                }
            }
            res = temp + to_string(countOfChar) + prevChar;
        }

        return res;
    }
};