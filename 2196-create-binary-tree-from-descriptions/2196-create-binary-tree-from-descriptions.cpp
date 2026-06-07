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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        // Step 1 & 2: Create nodes, link them, and record children
        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2] == 1;

            // Create parent node if it doesn't exist
            if (nodes.find(parentVal) == nodes.end()) {
                nodes[parentVal] = new TreeNode(parentVal);
            }
            
            // Create child node if it doesn't exist
            if (nodes.find(childVal) == nodes.end()) {
                nodes[childVal] = new TreeNode(childVal);
            }

            // Link the child to the parent
            if (isLeft) {
                nodes[parentVal]->left = nodes[childVal];
            } else {
                nodes[parentVal]->right = nodes[childVal];
            }

            // Mark this node as a child
            children.insert(childVal);
        }

        // Step 3: Find the root (the only node that is not a child)
        for (const auto& pair : nodes) {
            int nodeVal = pair.first;
            TreeNode* nodePtr = pair.second;
            
            if (children.find(nodeVal) == children.end()) {
                return nodePtr;
            }
        }

        return nullptr;
    }
};