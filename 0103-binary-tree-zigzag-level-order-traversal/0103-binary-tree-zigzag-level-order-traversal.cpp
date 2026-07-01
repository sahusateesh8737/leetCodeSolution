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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == nullptr){
            return ans;
        }
        queue<TreeNode*>q;
        bool left_right = true;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>row(size);
            for(int i =0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                int idx = left_right ? i : size -1 -i;
                row[idx] = curr->val;
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
               
            }
             left_right = !left_right;
                ans.push_back(row);

        }
        return ans;

    }
};