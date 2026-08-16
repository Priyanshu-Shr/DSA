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
    int getMin(TreeNode*root){
        if(root == NULL)
            return 0;
        
        while(root->left != NULL){
            root = root->left;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        
        if(root->val == key){
            //1st case -> No child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            //2nd case -> (one child either left or right)
            if(root->left != NULL && root->right == NULL){
                TreeNode*temp = root->left;
                delete root;
                return temp;
            }
            if(root->left == NULL && root->right != NULL){
                TreeNode*temp = root->right;
                delete root;
                return temp;
            }
            //3rd case -> both child
            if(root->left != NULL && root->right != NULL){
                int min = getMin(root->right);
                root->val = min;
                root->right = deleteNode(root->right,min);
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else{
            root->right = deleteNode(root->right,key);
        }
        return root;  
    }
};