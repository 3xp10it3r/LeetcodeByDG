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
    vector<int> v;
    void inOrder(TreeNode* root) {
        if(!root) return;
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }
    

    TreeNode* helper(int start, int end) {
        if(start > end) return NULL;
        int mid = start + (end - start) / 2;

        TreeNode* root = new TreeNode(v[mid]);

        root -> left = helper(start, mid - 1);
        root -> right = helper(mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return helper(0, v.size() - 1);
    }
};