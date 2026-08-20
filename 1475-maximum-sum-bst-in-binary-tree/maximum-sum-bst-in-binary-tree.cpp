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
class info{
    public:
        bool isBST;
        int maxi;
        int mini;
        int sum;
};

class Solution {
public:
    info solve(TreeNode*root,int & maxSum){
        if(root == NULL){
            return {true,INT_MIN,INT_MAX,0};
        }

        info left = solve(root->left,maxSum);
        info right = solve(root->right,maxSum);
        info ans;

        ans.maxi = max(root->val,right.maxi);
        ans.mini = min(root->val,left.mini);
        ans.sum = root->val + left.sum + right.sum;

        if(left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini ) ){
            ans.isBST= true;
            maxSum = max(maxSum,ans.sum);
        }else{
            ans.isBST = false;
        }
        
        
        return ans;
    }
    int maxSumBST(TreeNode* root) {
        int maxSum = INT_MIN;
        info ans = solve(root,maxSum);
        if(maxSum < 0)
            return 0;
        return maxSum;
    }   
};