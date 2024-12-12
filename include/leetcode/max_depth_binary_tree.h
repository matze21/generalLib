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
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxDepthL = 0;
        if(root->left){
            maxDepthL = maxDepth(root->left);
        }
        int maxDepthR = 0;
        if(root->right){
            maxDepthR = maxDepth(root->right);
        }
        return max(maxDepthL, maxDepthR)+1;
    }
};