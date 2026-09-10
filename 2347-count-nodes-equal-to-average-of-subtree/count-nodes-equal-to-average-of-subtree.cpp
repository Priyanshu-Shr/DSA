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
    pair<int,int> solve(TreeNode*root,int &ans){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = solve(root->left,ans);
        pair<int,int> right = solve(root->right,ans);
        pair<int,int> curr;

        curr.first = left.first + right.first + root->val;
        curr.second = left.second + right.second + 1;

        int avg = (curr.first)/(curr.second);

        if(avg == root->val){
            ans++;
        }
        
        return curr;
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        pair<int,int> temp = solve(root,ans);
        return ans;
    }
};