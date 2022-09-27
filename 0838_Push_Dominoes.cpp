// ! Date :- 27-09-2022

// * https://leetcode.com/problems/push-dominoes/

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        vector<int> nearestR(n, -1), nearestL(n, -1);
        int i = 0;
        while (i < n && dominoes[i] != 'R')
            ++i;
        for (i; i < n; i++)
        {
            if (dominoes[i] == 'R')
                nearestR[i] = 0;
            else if (dominoes[i] == 'L')
                nearestR[i] = -1;
            else
                nearestR[i] = nearestR[i - 1] == -1 ? -1 : nearestR[i - 1] + 1;
        }

        i = n - 1;
        while (i >= 0 && dominoes[i] != 'L')
            --i;
        for (i; i >= 0; --i)
        {
            if (dominoes[i] == 'L')
                nearestL[i] = 0;
            else if (dominoes[i] == 'R')
                nearestL[i] = -1;
            else
                nearestL[i] = nearestL[i + 1] == -1 ? -1 : nearestL[i + 1] + 1;
        }

        for (int i = 0; i < n; i++)
        {
            if (nearestL[i] == nearestR[i])
                continue;
            if (nearestL[i] == -1)
                dominoes[i] = 'R';
            else if (nearestR[i] == -1)
                dominoes[i] = 'L';
            else if (nearestL[i] > nearestR[i])
                dominoes[i] = 'R';
            else if (nearestL[i] < nearestR[i])
                dominoes[i] = 'L';
        }

        return dominoes;
    }
};

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        dominoes = 'L' + dominoes + 'R';
        int n = dominoes.size();
        int prevInd = 0;
        for (int i = 1; i < n; ++i)
        {
            if (dominoes[i] == 'L')
            {
                if (dominoes[prevInd] == 'L')
                    for (int x = prevInd + 1; x < i; ++x)
                        dominoes[x] = 'L';
                else if (dominoes[prevInd] == 'R')
                    for (int low = prevInd + 1, high = i - 1; low < high; ++low, --high)
                        dominoes[high] = 'L', dominoes[low] = 'R';
                prevInd = i;
            }
            else if (dominoes[i] == 'R')
            {
                if (dominoes[prevInd] == 'R')
                    for (int x = prevInd + 1; x < i; ++x)
                        dominoes[x] = 'R';
                prevInd = i;
            }
        }
        return dominoes.substr(1, n - 2);
    }
};