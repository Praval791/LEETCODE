// ! Date :- 11-07-2022

// * https://leetcode.com/problems/text-justification/

class Solution
{
    string createLine(vector<string> &words, int maxWidth)
    {
        int charsLen = 0;
        for (auto &word : words)
            charsLen += word.length();

        int totalSpaces = maxWidth - charsLen;
        if (words.size() == 1)
            return words[0] + string(totalSpaces, ' ');

        int noOfEquallyDividedSpaces = totalSpaces / (words.size() - 1);
        int extraSpaces = totalSpaces % (words.size() - 1);

        string line;
        int i;
        for (i = 0; i < words.size() - 1; i++)
            if (extraSpaces-- > 0)
                line += (words[i] + string(noOfEquallyDividedSpaces + 1, ' '));
            else
                line += (words[i] + string(noOfEquallyDividedSpaces, ' '));
        line += words[i];
        return line;
        // while(line.length() > 0 && line.back() == ' ') line.pop
    }

    string createEndLine(vector<string> &words, int maxWidth)
    {
        string line;
        for (auto &word : words)
            line += word + ' ';
        if (line.size() > maxWidth)
            line.pop_back();
        line += string(maxWidth - line.size(), ' ');
        return line;
    }

public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        // this will store all the words in the line
        vector<vector<string>> result;
        int charsLen = 0;
        vector<string> temp;
        for (const auto &word : words)
        {
            // if line is empty then push first word in the line
            if (charsLen == 0)
            {
                charsLen += word.length();
                temp.push_back(word);
            }
            // if we can't fill the new word in that line then push all the words in result [+1 for word seperator]
            else if (charsLen + word.length() + 1 > maxWidth)
            {
                result.push_back(temp);
                charsLen = word.length();
                temp.clear();
                temp.push_back(word);
            }
            // if we can fill more words in current line
            else
            {
                charsLen += word.length() + 1; // [+1 for word seperator]
                temp.push_back(word);
            }
        }
        // push the words of list line into result
        if (temp.size() > 0)
            result.push_back(temp);

        vector<string> ans;
        // createLine and push them into answer except the last one
        int i;
        for (i = 0; i < result.size() - 1; i++)
            ans.push_back(createLine(result[i], maxWidth));
        ans.push_back(createEndLine(result[i], maxWidth));
        return ans;
    }
};

// Optimized Space Complicity

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int n = words.size();

        int charsInCurrLine = 0;
        int spaceSeparators = 0; // By this we can also keep track of no. of words in line
        int startingWordOfLine = 0;
        for (int i = 0; i < n; i++)
        {
            // if we can add elements in current line
            if (charsInCurrLine + spaceSeparators + words[i].length() <= maxWidth)
            {
                spaceSeparators++;
                charsInCurrLine += words[i].length();
                // if inserted word is last word to be inserted
                if (i == n - 1)
                {
                    string result;
                    for (int k = startingWordOfLine; k < n; k++)
                        result += words[k] + ' ';
                    if (result.length() > maxWidth)
                        result.pop_back();
                    else
                        result += string(maxWidth - result.length(), ' ');
                    ans.push_back(result);
                }
            }
            else
            {
                string result;
                int spaces = maxWidth - charsInCurrLine;
                if (i == startingWordOfLine + 1)
                    result += words[startingWordOfLine] + string(spaces, ' ');
                else
                {
                    int noOfEquallyDividedSpaces = spaces / (i - startingWordOfLine - 1);
                    int extraSpaces = spaces % (i - startingWordOfLine - 1);
                    int k;
                    for (k = startingWordOfLine; k < i - 1; k++)
                    {
                        if (extraSpaces-- > 0)
                            result += words[k] + string(noOfEquallyDividedSpaces + 1, ' ');
                        else
                            result += words[k] + string(noOfEquallyDividedSpaces, ' ');
                    }
                    result += words[k];
                }
                ans.push_back(result);
                startingWordOfLine = i;
                charsInCurrLine = words[i].length();
                spaceSeparators = 1;
                if (i == n - 1)
                {
                    string result;
                    for (int k = startingWordOfLine; k < n; k++)
                        result += words[k] + ' ';
                    if (result.length() > maxWidth)
                        result.pop_back();
                    else
                        result += string(maxWidth - result.length(), ' ');
                    ans.push_back(result);
                }
            }
        }
        return ans;
    }
};
