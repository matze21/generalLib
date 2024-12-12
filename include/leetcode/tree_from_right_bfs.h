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
vector<int> rightSideView(TreeNode* root) {
        vector<int> out;
        if(!root){return out;}
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            const int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* fr = q.front();
                if(fr->left){q.push(fr->left);}
                if(fr->right){q.push(fr->right);}
                q.pop();
                if(i==size-1){
                    out.push_back(fr->val);
                }
            }
        }
        return out;
    }
    vector<int> rightSideView1(TreeNode* root) {
        TreeNode dummy(-1);
        vector<int> out;
        if(!root){return out;}
        queue<TreeNode*> q;
        q.push(root);
        q.push(&dummy);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left){ q.push(cur->left);}
            if(cur->right){q.push(cur->right);}

            if(q.front() == &dummy){
                out.push_back(cur->val);
                q.pop();
                q.push(&dummy);
            }
        }
        return out;
    }
};