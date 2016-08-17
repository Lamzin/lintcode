/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (root == NULL) {
            return 0;
        }
        int ans = -1000000009;
        if (root->start >= start && root->end <= end) {
            return root->max;
        }
        if (root->left != NULL && root->left->end >= start) {
            ans = max(ans, query(root->left, start, end));
        }
        if (root->right != NULL && root->right->start <= end) {
            ans = max(ans, query(root->right, start, end));
        }
        return ans;
    }
};