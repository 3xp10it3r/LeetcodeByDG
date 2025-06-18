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
    
    TreeNode* dfs(TreeNode* root, int x) {
        if(!root) return nullptr;
        
        if(root->val == x) return root;
        
        TreeNode* left = dfs(root->left, x);
        if(left != nullptr) return left;
        TreeNode* right = dfs(root->right, x);
        return right;
    }
    
    int getNodeCount(TreeNode* root) {
        if(!root) return 0;
        int cnt = 1;
        
        cnt += getNodeCount(root->left);
        cnt += getNodeCount(root->right);
        
        return cnt;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* player1Node = dfs(root, x);
        
        int c1 = getNodeCount(player1Node -> left);
        int c2 = getNodeCount(player1Node -> right);
        
        int upperCount = n - 1 - c1 - c2;

        int mx = max({upperCount, c1, c2});


        if(mx > n/2) return true;
        
        return false;
    }
};