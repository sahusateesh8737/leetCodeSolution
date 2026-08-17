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
int ans=-1;
int count=0;
    void helper(TreeNode* root, int k){
        if(!root){
            return;
        }
        if(root->left){
            helper(root->left,k);
        }
        count++;
        if(count==k){
            ans=root->val;
            return ;
        }
        if(root->right){
            helper(root->right,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        count=0;
        ans=-1;
        helper(root,k);
        return ans;
    }
};