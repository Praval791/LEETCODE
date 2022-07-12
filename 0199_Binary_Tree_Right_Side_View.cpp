// ! Date :- 11-07-2022

// * https://leetcode.com/problems/binary-tree-right-side-view/

/*
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */

// BFS
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {

        if (root == NULL)
            return {};
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            ans.push_back(q.front()->val);
            while (size--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);
            }
        }
        return ans;
    }
};

// DFS
class Solution
{
    vector<int> ans;
    const int MAX_VAL = 1000;
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    void dfs(TreeNode *root, int level)
    {
        if (root == NULL)
        {
            return;
        }
        if (ans[level] == MAX_VAL)
            ans[level] = root->val;
        dfs(root->right, level + 1);
        dfs(root->left, level + 1);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        int size = height(root);
        ans.resize(size, MAX_VAL);
        dfs(root, 0);
        return ans;
    }
};
