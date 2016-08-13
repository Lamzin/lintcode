class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        string c;
        if (a.length() < b.length()) {
            swap(a, b);
        }
        int sum = 0, index;
        for (int i = 0; i < a.length(); i++) {
            index = (int)a.length() - i - 1;
            if (index >= 0) {
                sum += a[index] - 48;
            }

            index = (int)b.length() - i - 1;
            if (index >= 0) {
                sum += b[index] - 48;
            }

            c += (sum % 2) + 48;
            sum /= 2;
        }
        while (sum) {
            c += (sum % 2) + 48;
            sum /= 2;
        }
        reverse(c.begin(), c.end());
        return c;
    }
};
