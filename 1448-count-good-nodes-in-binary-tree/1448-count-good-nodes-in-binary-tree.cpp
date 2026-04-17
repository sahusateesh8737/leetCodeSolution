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
    void dfs(TreeNode* root ,int rootVal , int & count){
        if(!root) return;
        if(root->val >= rootVal){
            count++;
            rootVal = root->val;
        }
        dfs(root->left , rootVal , count);
        dfs(root->right , rootVal , count);
    }
    int goodNodes(TreeNode* root) {
        TreeNode* temp = root;
        if(!root) return 0;
            int count =0;
            dfs(temp , root->val , count);
        return count;
    }
};