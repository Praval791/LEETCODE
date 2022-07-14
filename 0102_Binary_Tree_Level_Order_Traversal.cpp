// ! Date :- 13-07-2022

// * https://leetcode.com/problems/binary-tree-level-order-traversal/

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root != NULL)
        {
            queue<TreeNode *> q;
            q.push(root);
            while (!q.empty())
            {
                vector<int> temp;
                int size = q.size();
                for (int i = 1; i <= size; i++)
                {
                    TreeNode *node = q.front();
                    if (node->left != NULL)
                        q.push(node->left);
                    if (node->right != NULL)
                        q.push(node->right);
                    q.pop();
                    temp.push_back(node->val);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};