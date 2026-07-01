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
    void findPaths(TreeNode* root , int targetSum , vector<int>&current_path , vector<vector<int>>&result){
            if(root == nullptr){
                return ;
            }
            current_path.push_back(root->val);
            targetSum = targetSum - root->val;
            if(root->left == nullptr && root->right == nullptr && targetSum==0){
                result.push_back(current_path);
            }
            else {
                findPaths(root->left, targetSum , current_path , result);
                findPaths(root->right, targetSum , current_path , result);
            }
            current_path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>result;
        vector<int>current_path;
       findPaths(root , targetSum , current_path , result);
        return result;

    }
};