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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */

    TreeNode *result = NULL;

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        this->count(root, A, B);
        return this->result;
    }

    int count(TreeNode *root, TreeNode *A, TreeNode *B) {
        if (root == NULL) return 0;
        int ans = 0;
        if (root->left != NULL) {
            ans += this->count(root->left, A, B);
        }
        if (root->right != NULL) {
            ans += this->count(root->right, A, B);
        }
        if (root == A) {
            ans++;
        }
        if (root == B) {
            ans++;
        }
        if (ans == 2 && this->result == NULL) {
            this->result = root;
        }
        return ans;
    }
};
