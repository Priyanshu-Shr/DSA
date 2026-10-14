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
    int getHeight(TreeNode*root){
        if(root == NULL)
            return 0;
        
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return max(left,right) + 1;
    }

    void solve(TreeNode*root,int height, int MaxHeight,int&ans){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL && height ==MaxHeight){
            ans += root->val;
            return;
        }

        solve(root->left,height+1,MaxHeight,ans);
        solve(root->right,height+1,MaxHeight,ans); 
    }
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        int maxHeight = getHeight(root);
        solve(root,1,maxHeight,ans);
        return ans;
    }
};