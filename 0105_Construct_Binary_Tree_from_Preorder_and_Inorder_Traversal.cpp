// ! Date :- 14-07-2022

// * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    vector<int> preorder;
    int preOrderIndex;
    unordered_map<int, int> inorderIndexMap;

    TreeNode *util(int leftEnd, int rightEnd)
    {
        if (rightEnd < leftEnd)
            return NULL;
        int rootVal = preorder[preOrderIndex++];
        TreeNode *root = new TreeNode(rootVal);
        root->left = util(leftEnd, inorderIndexMap[rootVal] - 1);
        root->right = util(inorderIndexMap[rootVal] + 1, rightEnd);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        preOrderIndex = 0;
        int n = preorder.size();
        this->preorder = preorder;
        for (int i = 0; i < n; i++)
            inorderIndexMap[inorder[i]] = i;
        return util(0, n - 1);
    }
};
