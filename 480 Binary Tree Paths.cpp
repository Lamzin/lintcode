/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) {
            return vector<string>();
        }
        if (root->left == NULL && root->right == NULL) {
            return vector<string>(1, std::to_string(root->val));
        }
        vector<string> all_ways, ways;
        if (root->left != NULL) {
            ways = binaryTreePaths(root->left);
            all_ways.insert(all_ways.end(), ways.begin(), ways.end());
        }
        if (root->right != NULL) {
            ways = binaryTreePaths(root->right);
            all_ways.insert(all_ways.end(), ways.begin(), ways.end());
        }
        for (int i = 0; i < all_ways.size(); i++) {
            all_ways[i] = std::to_string(root->val) + "->" + all_ways[i];
        }
        return all_ways;
    }
};
