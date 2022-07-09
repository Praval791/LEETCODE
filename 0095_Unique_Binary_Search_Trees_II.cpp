// ! Date :- 08-07-2022

// * https://leetcode.com/problems/unique-binary-search-trees-ii/

/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */

// Brute Force (Recursion)
class Solution
{
    // possible boundary of root nodes
    vector<TreeNode *> DFS(int start, int end)
    {
        vector<TreeNode *> ans;
        if (start > end) // if start boundary is greater than end boundary means there will be no possible root
        {
            ans.push_back(NULL);
            return ans;
        }
        if (start == end) // if start boundary is equal to end boundary means there will be only one possible root
        {
            ans.push_back(new TreeNode(start));
            return ans;
        }
        for (int i = start; i <= end; i++) // i will become root node for left child and right child
        {
            vector<TreeNode *> leftSubTrees = DFS(start, i - 1); // generate all possible left children for current root (or iteration)
            vector<TreeNode *> rightSubTrees = DFS(i + 1, end);  // generate all possible right children for current root (or iteration)
            for (auto lTree : leftSubTrees)
                for (auto rTree : rightSubTrees)
                    ans.push_back(new TreeNode(i, lTree, rTree)); // make i as root for every possible combination and push them in ans
        }
        return ans;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        return DFS(1, n);
    }
};
