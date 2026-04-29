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
    int dfs(TreeNode * node , int current_number){
        if(node == nullptr){
            return 0;
        }
        current_number = current_number * 10 + node->val;
        if(node->left == nullptr && node->right ==nullptr){
            return current_number;
        }
        int leftsum  = dfs(node->left , current_number);
        int rightsum = dfs(node->right , current_number);
        return leftsum + rightsum;
    }
    int sumNumbers(TreeNode* root) {
       return  dfs(root , 0);
    }
};