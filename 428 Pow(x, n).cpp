class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if (n == 0) {
            return 1.0f;
        }
        if (n < 0) {
            n *= -1;
            x = 1.0f / x;
        }

        double result = 1.0f;
        for (int pow = 1; pow <= n; pow *= 2, x *= x) {
            if (pow & n) {
                result *= x;
            }
        }
        return result;
    }
};
