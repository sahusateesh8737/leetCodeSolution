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
    void dfs(TreeNode* node , string s, vector<string>&ans){
        if(!node) return;
        s = s + to_string(node->val);
        if (!node->left && !node->right) {
            ans.push_back(s);
        }
        else {
           
            s += "->";
            if (node->left) dfs(node->left, s, ans);
            if (node->right) dfs(node->right, s, ans);
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root){
            return ans;
        }
        dfs(root , "" ,ans);
        return ans;
    }
};