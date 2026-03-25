/**
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
class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        if(!root) return {INT_MIN, 0};

        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int data = root->val;

        int left = max(0, l.second);
        int right = max(0, r.second);

        int newNodeVal = max(left + data, right + data);
        int all = left + right + data;

        return {
            max({all, l.first, r.first}), 
            newNodeVal
        };
    }
    int maxPathSum(TreeNode* root) {
        return dfs(root).first;
    }
};