class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements,
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        for (int i = m - 1; i >= 0; i--) {
            A[i + n] = A[i];
        }

        for (int i = 0, aindex = n, bindex = 0; i < n + m; i++) {
            if (aindex == n + m) {
                A[i] = B[bindex++];
            } else if (bindex == n) {
                A[i] = A[aindex++];
            } else {
                if (A[aindex] < B[bindex]) {
                    A[i] = A[aindex++];
                } else {
                    A[i] = B[bindex++];
                }
            }
        }
    }
};
