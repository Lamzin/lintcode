/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int left = 0, right = n, middle;

        while (left < right) {
            middle = (left + right) / 2;
            if (SVNRepo::isBadVersion(middle)) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        return right;
    }
};
