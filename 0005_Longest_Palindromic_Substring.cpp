// ! Date :- 13-07-2022

// * https://leetcode.com/problems/longest-palindromic-substring/

// Brute force :- TLE
// ! TC :- O(N³)
class Solution
{
public:
    bool isPalindrome(const string &s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
    string longestPalindrome(string s)
    {
        int best_len = 0;
        int n = s.length();
        string long_str = "";
        for (int L = 0; L < n; L++)
        {
            for (int R = L; R < n; R++)
            {
                int len = R - L + 1;
                string subs = s.substr(L, len);
                if (len > best_len && isPalindrome(subs))
                {
                    best_len = len;
                    long_str = subs;
                }
            }
        }
        return long_str;
    }
};

// ! TC :- O(N²)
class Solution
{
public:
    string longestPalindrome(string s)
    {
        // code here
        int best_len = 0, best_start = 0;
        int n = s.length();
        // Let's take every char in string as a mid of any palindrome
        for (int mid = 0; mid < n; mid++)
        // Then check left and right chars from that mid
        {
            // if longest palindrome is of odd length
            for (int x = 0; x + mid < n && mid - x >= 0; x++)
            {
                if (s[mid - x] != s[mid + x])
                    break;
                int len = 2 * x + 1;
                if (len > best_len)
                {
                    best_len = len;
                    best_start = mid - x;
                }
            }
            // if longest palindrome is of even length
            for (int x = 0; x + 1 + mid < n && mid - x >= 0; x++)
            {
                if (s[mid - x] != s[mid + 1 + x])
                    break;
                int len = 2 * x + 2;
                if (len > best_len)
                {
                    best_len = len;
                    best_start = mid - x;
                }
            }
        }
        return s.substr(best_start, best_len);
    }
};

// Manacher’s Algorithm

/* Do not take a char as a new centre :-
 * 1. If the palindrome under it is totally contained in the current palindrome
 * 2. If the current Palindrome expends till the end of the input then there is no need to check for further characters.
 * 3. If palindrome under it expends all the way till the right edge but it's mirror palindrome expends beyond the left edge [Basically it's not a proper prefix]
 */

// * 4. Take a char as a new centre if palindrome under it is expends till the right edge and it's mirror palindrome expends all the way till the left edge [Basically it's a proper prefix]

class Solution
{
    const char DOLLAR = '$';

public:
    string longestPalindrome(string s)
    {
        // Preprocess the string to convert into abc -> $a$b$c$ to handle even length of palindromes
        int n = s.length();
        int N = 2 * n + 1;
        string newString;
        newString.resize(N);
        for (int i = 0; i < N; i++)
        {
            if (i & 1)
                newString[i] = s[i / 2];
            else
                newString[i] = DOLLAR;
        }

        vector<int> palindromeLengths(N);
        int start = 0;
        int end = 0;

        for (int mid = 0; mid < N;)
        {
            // expand around mid. See how far can go
            while (start > 0 && end < N - 1 && newString[start - 1] == newString[end + 1])
            {
                start--;
                end++;
            }
            // Set the longest length of palindrome around mid.
            palindromeLengths[mid] = end - start + 1;

            // *Case 2
            if (end == N - 1)
                break;

            /*Initialize new or next mid to be either end or end + 1 depending on if we dealing with even or odd number input
             *if end is point at = '$' then newMid = mid + 1
             *if end is point at = char then newMid = mid
             */
            int newMid = end + (mid & 1 ? 0 : 1);
            // check for new mid
            // iterate from mid + 1 to edge of current palindrome (end)
            for (int j = 1; j + mid <= end; j++)
            {
                /*	// *Handle Case 3 and case 1
                 *mid - j = gives left mirror
                 *(end - mid - j) = gives all the element from mid + j to end
                 *2 *(end - mid - j) + 1 = maximum possible length of palindrome of mirror and if it expends beyond the left edge then it can't be a centre of longest palindrome or (next mid)
                 */
                palindromeLengths[j + mid] = min(palindromeLengths[mid - j], 2 * (end - mid - j) + 1);

                /*	// *Case 4
                 *check for case 4 and find next mid
                 */
                if (mid + j + palindromeLengths[mid - j] / 2 == end)
                {
                    newMid = mid + j;
                    break;
                }
            }
            mid = newMid;
            end = mid + palindromeLengths[mid] / 2;
            start = mid - palindromeLengths[mid] / 2;
        }

        // find maximum length of palindrome
        int best_len = 0, best_start = 0;
        for (int i = 0; i < N; i++)
        {
            if (best_len < palindromeLengths[i])
            {
                best_len = palindromeLengths[i];
                best_start = i - best_len / 2;
            }
        }

        // Post-process the string and remove dollar signs
        string ans;
        for (int j = 0; j < best_len; j++)
            if (newString[j + best_start] != DOLLAR)
                ans += newString[j + best_start];
        return ans;
    }
};
