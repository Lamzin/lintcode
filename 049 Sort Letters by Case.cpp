class Solution {
public:
    /**
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int downcase = 0, uppercase = letters.size() - 1;
        while (downcase < uppercase) {
            if (letters[downcase] >= 'a' && letters[downcase] <= 'z') {
                downcase++;
            } else {
                swap(letters[downcase], letters[uppercase]);
                uppercase--;
            }
        }
    }
};
