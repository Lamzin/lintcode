class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        if (n <= 0) return "";
        std::string current = "1", next;
        for (int i = 2; i <= n; i++) {
            int sequence_count = 1;
            for (int j = 1; j < current.length(); j++) {
                if (current[j] == current[j - 1]) {
                    sequence_count++;
                } else {
                    next += std::to_string(sequence_count) + current[j - 1];
                    sequence_count = 1;
                }
            }

            next += std::to_string(sequence_count) + current[current.length() - 1];
            current = next;
            next.clear();
        }
        return current;
    }
};
