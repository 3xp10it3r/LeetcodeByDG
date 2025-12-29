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
    int rob(TreeNode* root) {
        vector<int> options = travel(root);

        return max(options[0], options[1]);
    }

    vector<int> travel(TreeNode* root) {
        if(root == nullptr) {
            return {0, 0};
        }

        vector<int> leftOptions = travel(root->left);
        vector<int> rightOptions = travel(root->right);

        vector<int> options;

        int take = root->val + leftOptions[1] + rightOptions[1];

        int notTake = max(leftOptions[0], leftOptions[1]) + 
                      max(rightOptions[0], rightOptions[1]);

        return {take, notTake};
    }
};