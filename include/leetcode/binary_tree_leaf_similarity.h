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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leave1;
        findLeaves(leave1, root1);
        vector<int> leave2;
        findLeaves(leave2, root2);
        
        return leave1 == leave2;
    }

    void findLeaves(vector<int>& leaves, TreeNode* root1){
        stack<TreeNode*> stack;
        stack.push(root1);
        while(!stack.empty()){
            TreeNode* top = stack.top();
            stack.pop();
            const bool isLeave{!top->left && !top->right};
            if(top->right){
                stack.push(top->right);
            }
            if(top->left){
                stack.push(top->left);
            }
            if(isLeave){
                leaves.push_back(top->val);
            }
        }
    }

    
};