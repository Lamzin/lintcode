class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        for (int i = 0; i < A.size(); i++) {
            int index = i;
            while (index && A[index] < A[(index - 1) / 2]) {
                swap(A[index], A[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
        }
    }
};
