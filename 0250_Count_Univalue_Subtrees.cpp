// ! Date :- 15-07-2022

// * https://leetcode.com/problems/count-univalue-subtrees/
// * https://www.codingninjas.com/codestudio/problems/unival-trees_697311

/*
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution
{

    bool dfs(TreeNode *root, int &count)
    {
        if (!root)
            return true;
        bool left = dfs(root->left, count);
        bool right = dfs(root->right, count);

        if ((root->left && (root->left->data != root->data)) or (root->right && (root->right->data != root->data)))
            return false;
        if (right && left)
        {
            count++;
            return true;
        }
        return false;
    }

    int countUnivalSubtrees(TreeNode *root)
    {
        // Write your code here.
        int count = 0;
        dfs(root, count);
        return count;
    }
}